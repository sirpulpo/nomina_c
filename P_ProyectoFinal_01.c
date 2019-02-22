#include<stdio.h>
#include<string.h>


float TotEmp, Nbase, Nadmi, Ndesa, TotPag=0, TotSeg, TotImp, ImssB, ImssA, ImssD;
float sb=0, sa=0, sd=0;
int mnu, menu, menu2, memp, regreso, opcion;
float ISRB[15], ISRA[15], ISRD[15];
float isrb=0, isra=0, isrd=0, isrt=0;
char EBN[50][50], EAN[50][50], EDN[50][50];
char EBR[15], EAR[15], EDR[15];
float EBS[15], EAS[15], EDS[15];
int EBF[15], EAF[15], EDF[15];


void DatosBase(){
	int i;
	for(i=0; i<Nbase; i++)
	{
		system("cls");
		printf("Empleados Base\n\n");
		printf("Para el empleado %d.\n",i+1);
		fflush(stdin);
		printf("Nombre del empleado: ");
		gets(EBN[i]);
		printf("RFC del empleado: ");
		scanf("%s",&EBR[i]);
		printf("Salario diario del empleado: ");
		scanf("%f",&EBS[i]);
		printf("Faltas semanales del empleado: ");
		scanf("%d",&EBF[i]);
		if(EBF[i]==0)
		{
			EBS[i]=EBS[i]+EBS[i];
		}
	}
}


void DatosAdmi(){
	int i;
	for(i=0; i<Nadmi; i++)
	{
		system("cls");
		printf("Empleados Administrativos\n\n");
		printf("Para el empleado %d.\n",i+1);
		fflush(stdin);
		printf("Nombre del empleado: ");
		gets(EAN[i]);
		printf("RFC del empleado: ");
		scanf("%s",&EAR[i]);
		printf("Salario diario del empleado: ");
		scanf("%f",&EAS[i]);
		printf("Faltas semanales del empleado: ");
		scanf("%d",&EAF[i]);
		if(EAF[i]==0)
		{
			EAS[i]=EAS[i]+EAS[i];
		}
	}
}


void DatosDesa(){
	int i;
	for(i=0; i<Ndesa; i++)
	{
		system("cls");
		printf("Empleados desarrolladores\n\n");
		printf("Para el empleado %d.\n",i+1);
		fflush(stdin);
		printf("Nombre del empleado: ");
		gets(EDN[i]);
		printf("RFC del empleado: ");
		scanf("%s",&EDR[i]);
		printf("Salario diario del empleado: ");
		scanf("%f",&EDS[i]);
		printf("Faltas semanales del empleado: ");
		scanf("%d",&EDF[i]);
		if(EDF[i]==0)
		{
			EDS[i]=EDS[i]+EDS[i];
		}
	}
}


float ISR(float sueldo){
   	float isr, base, tasa;
	if (sueldo<=16.32)                        
	{
		base=sueldo-0.01;
		base=base*4;
		tasa=base*0.0192;
		isr=tasa+0.00;
	}
    else if (sueldo>16.32 && sueldo<=138.50) 
    {
    	  base=sueldo-16.33;
    	  base=base*4;
    	  tasa=base*0.0640;
    	  isr=tasa+0.31;
    }
	else if (sueldo>138.50 && sueldo<=243.40)  
	{
		base=sueldo-138.52;
		base=base*4;
		tasa=base*0.1088;
		isr=tasa+8.13;
	}
	else if (sueldo>243.40 && sueldo<=282.94) 
	{
		 base=sueldo-243.41;
		 base=base*4;
		 tasa=base*0.16;
		 isr=tasa+19.55;
	}         
	else if (sueldo>282.94 && sueldo<=383.23)
	{
		base=sueldo-282.95;
		base=base*4;
		tasa=base*0.1792;
		isr=tasa+25.87;
	}              
	else if (sueldo>383.23 && sueldo<=683.23)  
	{
		base=sueldo-338.77;
		base=base*4;
		tasa=base*0.2136;
		isr=tasa+35.88;
	}               
	else if (sueldo>683.23 && sueldo <=1076.87) 
	{
		base=sueldo-683.24;
		base=base*4;
		tasa=base*0.2352;
		isr=tasa+109.45;
	}               
	else if (sueldo>1076.87 && sueldo <=2055.92) 
	{
		base=sueldo-1076.88;
		base=base*4;
		tasa=base*0.3;
		isr=tasa+202.04;
	}                 
	else if (sueldo>2055.92 && sueldo <=2741.23) 
	{
		base=sueldo-2055.93;
		base=base*4;
		tasa=base*0.32;
		isr=tasa+495.75;
	}                
	else if (sueldo>2741.23 && sueldo <=8223.68) 
	{
		base=sueldo-2741.24;
		base=base*4;
		tasa=base*0.34;
		isr=tasa+715.05;
	}               
	else if(sueldo>8223.68)
	{
		 base=sueldo-8223.69;
		 base=base*4;
		 tasa=base*0.35;
		 isr=tasa+2579.09;
	}         
    return isr;							                            
} 


void TotalBase()
{
	int i;
	for(i=0; i<Nbase; i++)
	{
		sb=sb+EBS[i];
	}
	sb=sb*6;
	printf("Total en salarios de empleados base es: %f\n",sb);
	ImssB=sb*.2375;
	printf("Total en gastos de seguro de empleados base es: %f\n",ImssB);
	for(i=0; i<Nbase ; i++)
	{
		isrb=isrb+ISRB[i];
	}
	isrb=isrb*6;
	printf("Total en impuestos de salario de empleados base es: %f\n\n",isrb);
}


void TotalAdmi(){
	int i;
	for(i=0; i<Nadmi; i++)
	{
		sa=sa+EAS[i];
	}
	sa=sa*12;
	printf("Total en salrios de administrativos es: %f\n",sa);
	ImssA=sa*.2375;
	printf("Total en gastos de seguro de administrativos es: %f\n",ImssA);
	for(i=0; i<Nadmi ; i++)
	{
		isra=isra+ISRA[i];
	}
	isra=isra*12;
	printf("Total en impuestos de salario de empleados administrativos es: %f\n\n",isra);
}


void TotalDesa(){
	int i;
	for(i=0; i<Ndesa; i++)
	{
		sd=sd+EDS[i];
	}
	sd=sd*24;
	printf("Total en gastos de desarrolladores es: %f\n",sd);
	ImssD=sd*.2375;
	printf("Total en gastos de seguro de desarrolladores es: %f\n",ImssD);
	for(i=0; i<Ndesa ; i++)
	{
		isrd=isrd+ISRD[i];
	}
	isrd=isrd*24;
	printf("Total en impuestos de salario de empleados desarrolladores es: %f\n\n",isrd);
}


void Totales(){
	int i;
	TotPag=sb+sa+sd;
	printf("Total a pagar es de %f\n",TotPag);
	TotSeg=TotPag*.2375;
	printf("Total en gastos de seguro es de %f\n",TotSeg);
	TotImp=isrb+isra+isrd;
	printf("Total en impuestos es de %f\n",TotImp);
	
}
int main()
{
	int i;
	printf("\t\tUniversidad Nacional Aut\xA2noma de M\x82xico");
    printf("\n\t\tFacultad de Estudios Superiores Acatl\xA0n");
    printf("\n\t\t   Matem\xA0ticas Aplicadas y Computaci\xA2n");
    printf("\n\t\t\t     Programaci\xA2n I");
    printf("\n\t\t   Proyecto final: C\xA0lculo de n\xA2mina.\n\n\n\n\n");
    
	system("pause");
    system("cls");
    printf("\t\t\20 Programa dirigido para jefes o\n\t\tadministrativos contables de la empresa.\n");
    printf("\n\t\tEste programa tiene como objetivo calcular\n\t\tla n\xA2mina de una empresa.");
    printf("\n\n\tLa n\xA2mina es un documento contable en el que se registran las\n\tpercepciones a pagar a los empleados y las ");
    printf("deducciones que deber\xA0\n\trestar del salario. De esta operaci\xA2n aritm\x82tica se obtiene la\n\tcantidad final que el trabajador ");
    printf("recibir\xA0 en un determinado per\xA1odo.\n\n\n\n\n\n\n\n");
    system("pause");
    system("cls");
	do{  
	    printf("\t\t\t\tSoftware Heuristic Solutions\n\t\t\t\t_________\n\n");
		printf("Cuantos empleados a facturar: ");
		scanf("%f",&TotEmp);
		printf("Cuantos empleados base: ");
		scanf("%f",&Nbase);
		printf("Cuantos empleados administrativos: ");
		scanf("%f",&Nadmi);
		printf("Cuantos empleados desarrolladores: ");
		scanf("%f",&Ndesa);
		while((Nbase+Nadmi+Ndesa)!=TotEmp)
		{
			printf("El total de empleados que me dijo no coincide!\n");
			printf("Cuantos empleados base: ");
			scanf("%f",&Nbase);
			printf("Cuantos empleados administrativos: ");
			scanf("%f",&Nadmi);
			printf("Cuantos empleados desarrolladores: ");
			scanf("%f",&Ndesa);
		}
		if(Nbase>0)
		{
			DatosBase(EBR, EBS, EBF);
		}
		if(Nadmi>0)
		{
			DatosAdmi(EAR, EAS, EAF);
		}
		if(Ndesa>0)
		{
			DatosDesa(EDR, EDS, EDF);
		}
		for(i=0; i<Nbase; i++)
		{
			ISRB[i]=ISR(EBS[i]);
		}
		for(i=0; i<Nadmi; i++)
		{
			ISRA[i]=ISR(EAS[i]);
		}
		for(i=0; i<Ndesa; i++)
		{
			ISRD[i]=ISR(EDS[i]);
		}
		do{
			system("cls");
			printf("Que desea ver?\n");
			printf("1-Datos personales.\n");
			printf("2-Gastos totales.\t");
			scanf("%d",&mnu);
			while(mnu!=1 && mnu!=2)
			{
				printf("Opcion no valida.\n");
				printf("1-Datos personales.\n");
			    printf("2-Gastos totales.\t");
			    scanf("%d",&mnu);
			}
			if(mnu==1)
			{
				system("cls");
				printf("Datos personales.\n");
				printf("1-Empleados Base.\n");
				printf("2-Empleados Administrativos.\n");
				printf("3-Empleados Desarrolladores.\t");
				scanf("%d",&menu);
				while(menu!=1 && menu!=2 && menu!=3)
				{
					printf("Opcion no valida.\n");
					printf("Datos personales.\n");
					printf("1-Empleados Base.\n");
					printf("2-Empleados Administrativos.\n");
					printf("3-Empleados Desarrolladores.\t");
					scanf("%d",&menu);
				}
				if(menu==1)
				{
					system("cls");
					printf("1-Empleados Base.\n");
					printf("Seleccione un empleado.\n");
					for (i=0; i<Nbase; i++)
					{
						printf("%d-%s.\n",(i+1),EBN[i]);
					}
					scanf("%d",&memp);
					system("cls");
					printf("%s\n",EBN[(memp-1)]);
					printf("%s\n",EBR[(memp-1)]);
					printf("%f\n",EBS[(memp-1)]);
					printf("%d\n",EBF[(memp-1)]);
				}
				else if(menu==2)
				{
					system("cls");
					printf("2-Empleados Administrativos.\n");
					printf("Seleccione un empleado.\n");
					for (i=0; i<Nadmi; i++)
					{
						printf("%d-%s.\n",(i+1),EAN[i]);
					}
					scanf("%d",&memp);
					system("cls");
					printf("%s\n",EAN[(memp-1)]);
					printf("%s\n",EAR[(memp-1)]);
					printf("%f\n",EAS[(memp-1)]);
					printf("%d\n",EAF[(memp-1)]);
				}
				else if(menu==3)
				{
					system("cls");
					printf("3-Empleados Desarrolladores.\t");
					printf("Seleccione un empleado.\n");
					for (i=0; i<Ndesa; i++)
					{
						printf("%d-%s.\n",(i+1),EDN[i]);
					}
					scanf("%d",&memp);
					system("cls");
					printf("%s\n",EDN[(memp-1)]);
					printf("%s\n",EDR[(memp-1)]);
					printf("%f\n",EDS[(memp-1)]);
					printf("%d\n",EDF[(memp-1)]);
				}
			}
			else if(mnu==2)
			{
				system("cls");
				printf("Gastos Totales.\n");
				printf("Que datos desea ver?\n\n");
				printf("1-Gastos totales en empleados Base.\n");
				printf("2-Gastos totales en empleados Administrativos.\n");
				printf("3-Gastos totales en empleados desarrolladores.\n");
				printf("4-Gastos totales Generales.\t");
				scanf("%d",&menu2);
				while(menu2!=1 && menu2!=2 && menu2!=3 && menu2!=4)
				{
					system("cls");
					printf("Escoja una opcion del menu.");
					printf("Que datos desea ver?\n\n");
					printf("1-Gastos totales en empleados Base.\n");
					printf("2-Gastos totales en empleados Administrativos.\n");
					printf("3-Gastos totales en empleados Desarrolladores.\n");
					printf("4-Gastos totales Generales.\n");
					scanf("%d",&menu2);
				}
				if(menu2==1)
				{
					system("cls");
					TotalBase();
				}
				else if(menu2==2)
				{
					system("cls");
					TotalAdmi();
				}
				else if(menu2==3)
				{
					system("cls");
					TotalDesa();
				}
				else if(menu2==4)
				{
					system("cls");
					Totales();
				}
		    }
		    printf("\nRegresar?\tSI=1\tNO=2\t");
			scanf("%d",&regreso);
			while(regreso!=1 && regreso!=2)
			{
				printf("opcion no valida.\n");
				printf("\nRegresar?\tSI=1\tNO=2\t");
			   	scanf("%d",&regreso);
			}
	    }while(regreso==1);
	    printf("Desea repetir el programa?\n");
	    printf("\tSI=1\tNO=2\t");
	    scanf("%d",&opcion);
	    while(opcion!=1 && opcion!=2)
	    {
	    	printf("Opcion no valida.\n");
	    	printf("Desea repetir el programa?\n");
	        printf("\tSI=1\tNO=2\t");
	        scanf("%d",&opcion);
	    }
    }while(opcion==1);
	return 0;
}
