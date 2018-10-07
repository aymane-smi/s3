#include<stdio.h>
#include<math.h>
#define pi 3.1415926
#define zero 0.0000001
double rectangle(double, double, int );
double trapezes(double, double, int );
double fexp(double );
main(){
	double x, y, alpha=1./2, r;
	int n;
	printf("donne une valeur pour n:");
	scanf("%d", &n);
	do{
		printf("donne une valeur de a puis b:");
		scanf("%lf %lf", &x, &y);
	}while(x!=0 && y<1000);
	printf("la valeur de l'integrale avec methode de rectangle est:%lf\n", rectangle(x, y, n));
	printf("la valeur de l'integrale avec methode de trapezes est:%lf\n", trapezes(x, y, n));
	//trapezes
	r = pow(trapezes(x, y, n),2)*(1./alpha);
	if(r-pi<zero && r-pi>0)
		printf("l'approximation du pi est:%lf\n", r);
	//rectangle
	r = pow(trapezes(x, y, n),2)*(1./alpha);
	if(r-pi<zero & r-pi>0)
		printf("l'approximation du pi est:%lf\n", r);
}
double rectangle(double a, double b, int n){
	double s=0, h=(b-a)/n, x;
	int i=0;
	for(i;i<n;i++){
		x = a+i*h;
		s += fexp(x); 
	}
	return h*s; 
}
double trapezes(double a, double b, int n){
	double s=0, h=(b-a)/n, x, x1;
	int i=0;
	for(i;i<n;i++){
		x = a+i*h;
		x1 = a+(i+1)*h;
		s += (fexp(x)+fexp(x1))/2.; 
	}
	return h*s;
}
double fexp(double x){
	return exp(-pow(x,2)/2.);
}
