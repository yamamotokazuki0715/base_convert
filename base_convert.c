#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//引数の2進数における1の数をカウントする
int count_bits(unsigned x){
	int cnt = 0;
	while(x){
		if(x & 1U)
			cnt++;
		x >>= 1;
	}
	return cnt;
}

//環境に応じたbit数を計算する 0000 0000...を反転し、count_bits関数で1の数をカウント
int env_bits(void){
	return count_bits(~0U);
}

//1bitずつ表示
void print_bits(unsigned x){
	int cnt = 0;
	for(int i = env_bits() - 1; i >= 0; i--){
		putchar(((x >> i) & 1U)? '1' : '0');
		cnt++;
		if(!(cnt % 4))
			putchar(' ');
	}
}

//nビット右シフト回転
int Rrotate(unsigned x, int n){
	unsigned a = x;
	x >>= n;
	a <<= (env_bits() - n);
	return (x | a);
}

//nビット左シフト回転
int Lrotate(unsigned x, int n){
	unsigned a = x;
	x <<= n;
	a >>= (env_bits() - n);
	return (x | a);
}

int main(void){
	unsigned int x;
	int select_base; //進数を選択する変数 
	
	puts("進数を選択してください。");
	
	while(1){
		printf("10進数 : 1\n16進数 : 2\n");
		scanf("%d", &select_base);
		if(select_base == 1 || select_base == 2)
			break;
		else
			puts("\n正しい数を入力してください");
	}
	
	switch(select_base){
		case 1 : printf("\n10進数を入力\n X : "); scanf("%d",&x); break;
		case 2 : printf("\n16進数を入力\n X : "); scanf("%x",&x); break;
	}
	
	int processing; //処理内容を選択する変数
	
	printf("\n行う操作を選んでください。\n");
	
	while(1){
		puts("Xを2進数で表示        : 1");
		puts("Xの各ビットを反転     : 2");
		puts("論理積(AND)           : 3");
		puts("論理和(OR)            : 4");
		puts("排他的論理和(XOR)     : 5");
		puts("右にnビットシフト     : 6");
		puts("左にnビットシフト     : 7");
		puts("右にnビットシフト回転 : 8");
		puts("左にnビットシフト回転 : 9");
		
		scanf("%d",&processing);
		if(processing >= 1 && processing <= 9)
			break;
		else
			puts("\n正しい数を入力してください");
	}
	
	putchar('\n');
	
	unsigned int y;
	
	if(processing == 1){
		printf(" X = ");
		print_bits(x);
	}
	
	if(processing == 2){
		printf(" X = ");
		print_bits(x);
		printf("\n\n");
		printf(" NOT X = ");
		print_bits(~x);
	}
	
	if(processing == 3){
		printf(" X = ");
		print_bits(x);
		if(select_base == 1){
			printf("\nもう一つの10進数を入力\n Y : "); scanf("%d",&y);
		}
		else{
			printf("\nもう一つの16進数を入力\n Y : "); scanf("%x",&y);
		}
		printf(" Y =  ");
		print_bits(y);
		printf("\n\n");
		printf(" X AND Y = ");
		print_bits(x&y);
	}
	
	if(processing == 4){
		printf(" X = ");
		print_bits(x);
		if(select_base == 1){
			printf("\nもう一つの10進数を入力\n Y : "); scanf("%d",&y);
		}
		else{
			printf("\nもう一つの16進数を入力\n Y : "); scanf("%x",&y);
		}
		printf(" Y =  ");
		print_bits(y);
		printf("\n\n");
		printf(" X OR Y = ");
		print_bits(x|y);
	}
	
	if(processing == 5){
		printf(" X = ");
		print_bits(x);
		if(select_base == 1){
			printf("\nもう一つの10進数を入力\n Y : "); scanf("%d",&y);
		}
		else{
			printf("\nもう一つの16進数を入力\n Y : "); scanf("%x",&y);
		}
		printf(" Y =  ");
		print_bits(y);
		printf("\n\n");
		printf(" X XOR Y = ");
		print_bits(x^y);
	}
	
	if(processing == 6){
		printf(" X = ");
		print_bits(x);
		printf("\nシフトしたい数を入力\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" Xを右に%dビットシフトすると\n",y);
		print_bits(x >> y);
	}
	
	if(processing == 7){
		printf(" X = ");
		print_bits(x);
		printf("\nシフトしたい数を入力\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" Xを左に%dビットシフトすると\n",y);
		print_bits(x << y);
	}
	
	if(processing == 8){
		printf(" X = ");
		print_bits(x);
		printf("\nシフト回転したい数を入力\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" Xを右に%dビットシフト回転すると\n",y);
		print_bits(Rrotate(x,y));
	}
	
	if(processing == 9){
		printf(" X = ");
		print_bits(x);
		printf("\nシフト回転したい数を入力\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" Xを左に%dビットシフト回転すると\n",y);
		print_bits(Lrotate(x,y));
	}
	
	putchar('\n');
	
	return 0;
}