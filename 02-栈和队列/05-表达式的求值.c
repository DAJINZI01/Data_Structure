#include <stdio.h>
#include "linkStack.h"

/*
 * 基本策略：将中缀表达式转换为后缀表达式
 *
 * 1、运算数的相对顺序不变
 * 2、运算符号顺序发生改变
 * 	需要存储 "等待中" 的运算符号
 * 	要将当前运算符号与“等待中”的最后一个运算符号比较
 *
 * 从头到尾读取中缀表达式的每个对象，对不同的对象按不同的情况处理
 * 1、运算数：直接输出
 * 2、左括号：压栈
 * 3、右括号：将栈顶的运算符弹出并输出，直到遇到左括号（出栈，不用输出）
 * 4、运算符：
 * 		若优先级大于栈顶运算符时，则把它压栈
 * 		若优先级小于栈顶运算符时，将栈顶运算符弹出并输出；
 * 		在比较新的栈顶运算符，直到该运算符大于栈顶运算符优先级为止，
 * 		然后将该运算符压栈
 * 5、若各对象处理完毕，则把栈中保留的运算符一并输出
 *
 * */

int priority(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return 0;
}

int compare(char c1, char c2){
	int prior1 = priority(c1);
      	int prior2 = priority(c2);

	if(prior1 >= prior2)
		return 1;
	else if(prior1 < prior2)
		return -1;
	return 0;
}

void change(const char* str1, char *str2){
	LinkStack *stack = NULL;
	char c, topc;
	createStack(&stack);
	char *p = (char *)str1;
	while(*p != '\0'){
		if(*p >= '0' && *p <= '9' )// 数字, 直接输出到缓冲区
			*str2++ = *p;
		else if(*p == '('){
			push(stack, *p);// 左括号直接压栈
		}
		else if(*p == ')'){// 右括号 不用压栈
			pop(stack, &c);			
			while(c != '('){// 一直弹出栈顶元素，直到遇到左括号
				*str2++ = c;
				pop(stack, &c);
			}
		}
		else {
			if(isEmpty(stack))// 操作符第一次入栈, 不需要比较直接进栈
				push(stack, *p);
			else
			{
				top(stack, &topc);
				while(compare(topc, *p) == 1){// 栈顶优先级高, 一直弹出，直到优先级低
					pop(stack, &c);	
					*str2++ = c;
					top(stack, &topc);
				}	
				if(compare(topc, *p) == -1)// 栈顶优先级低，元素压栈
					push(stack, *p);
			}
		}
		p++;
	}
	while(!isEmpty(stack))// 对象处理完毕，将栈中的元素一并输出
		pop(stack, &*str2++);
	destoryStack(stack);
}

int Op(int a, char c, int b){// 计算函数
	int result = 0;
	switch(c){
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*': result = a * b; break;
		case '/': 
			  if(b == 0) {printf("divide by zero!\n"); return -1;}
			  result = a / b; break;
		default: result = 0;
	}
	return result;
}

int computer(const char *exp){
	if(exp == NULL)
		return -1;

	char op;
	int a, b;
	// 创建一个栈
	int stack[1024] = {0};
	int top = -1;

	char *p = (char *)exp;
	while(*p != '\0'){
		if(*p >= '0' && *p <= '9'){// 数字直接压栈，等待操作符处理
			stack[++top] = 	*p - '0';
		}
		else {// 是操作符，弹出两个栈顶元素，进行相应的运算，将结果压栈
			op = *p;
			b = stack[top--];
			a = stack[top--];
			stack[++top]  = Op(a, op, b);
		}
		p++;
	}
	// 最后弹出栈顶元素
	
	return stack[top--]; 
}


int main(){
	char buf1[1024] = {0};
	char buf2[1024] = {0};
	printf("请输入一个中缀表达式：");
	scanf("%s", buf1);
	printf("\n-------------------------\n");
	change(buf1, buf2);
	printf("转换为后缀表达式：%s\n", buf2);
	int result = 0;
	result = computer(buf2);
	printf("表达式的计算结果为：%d\n", result);

}

