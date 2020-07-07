#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//������2�i���ɂ�����1�̐����J�E���g����
int count_bits(unsigned x){
	int cnt = 0;
	while(x){
		if(x & 1U)
			cnt++;
		x >>= 1;
	}
	return cnt;
}

//���ɉ�����bit�����v�Z���� 0000 0000...�𔽓]���Acount_bits�֐���1�̐����J�E���g
int env_bits(void){
	return count_bits(~0U);
}

//1bit���\��
void print_bits(unsigned x){
	int cnt = 0;
	for(int i = env_bits() - 1; i >= 0; i--){
		putchar(((x >> i) & 1U)? '1' : '0');
		cnt++;
		if(!(cnt % 4))
			putchar(' ');
	}
}

//n�r�b�g�E�V�t�g��]
int Rrotate(unsigned x, int n){
	unsigned a = x;
	x >>= n;
	a <<= (env_bits() - n);
	return (x | a);
}

//n�r�b�g���V�t�g��]
int Lrotate(unsigned x, int n){
	unsigned a = x;
	x <<= n;
	a >>= (env_bits() - n);
	return (x | a);
}

int main(void){
	unsigned int x;
	int select_base; //�i����I������ϐ� 
	
	puts("�i����I�����Ă��������B");
	
	while(1){
		printf("10�i�� : 1\n16�i�� : 2\n");
		scanf("%d", &select_base);
		if(select_base == 1 || select_base == 2)
			break;
		else
			puts("\n������������͂��Ă�������");
	}
	
	switch(select_base){
		case 1 : printf("\n10�i�������\n X : "); scanf("%d",&x); break;
		case 2 : printf("\n16�i�������\n X : "); scanf("%x",&x); break;
	}
	
	int processing; //�������e��I������ϐ�
	
	printf("\n�s�������I��ł��������B\n");
	
	while(1){
		puts("X��2�i���ŕ\��        : 1");
		puts("X�̊e�r�b�g�𔽓]     : 2");
		puts("�_����(AND)           : 3");
		puts("�_���a(OR)            : 4");
		puts("�r���I�_���a(XOR)     : 5");
		puts("�E��n�r�b�g�V�t�g     : 6");
		puts("����n�r�b�g�V�t�g     : 7");
		puts("�E��n�r�b�g�V�t�g��] : 8");
		puts("����n�r�b�g�V�t�g��] : 9");
		
		scanf("%d",&processing);
		if(processing >= 1 && processing <= 9)
			break;
		else
			puts("\n������������͂��Ă�������");
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
			printf("\n�������10�i�������\n Y : "); scanf("%d",&y);
		}
		else{
			printf("\n�������16�i�������\n Y : "); scanf("%x",&y);
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
			printf("\n�������10�i�������\n Y : "); scanf("%d",&y);
		}
		else{
			printf("\n�������16�i�������\n Y : "); scanf("%x",&y);
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
			printf("\n�������10�i�������\n Y : "); scanf("%d",&y);
		}
		else{
			printf("\n�������16�i�������\n Y : "); scanf("%x",&y);
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
		printf("\n�V�t�g�������������\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" X���E��%d�r�b�g�V�t�g�����\n",y);
		print_bits(x >> y);
	}
	
	if(processing == 7){
		printf(" X = ");
		print_bits(x);
		printf("\n�V�t�g�������������\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" X������%d�r�b�g�V�t�g�����\n",y);
		print_bits(x << y);
	}
	
	if(processing == 8){
		printf(" X = ");
		print_bits(x);
		printf("\n�V�t�g��]�������������\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" X���E��%d�r�b�g�V�t�g��]�����\n",y);
		print_bits(Rrotate(x,y));
	}
	
	if(processing == 9){
		printf(" X = ");
		print_bits(x);
		printf("\n�V�t�g��]�������������\n n : "); scanf("%d",&y);
		printf("\n\n");
		printf(" X������%d�r�b�g�V�t�g��]�����\n",y);
		print_bits(Lrotate(x,y));
	}
	
	putchar('\n');
	
	return 0;
}