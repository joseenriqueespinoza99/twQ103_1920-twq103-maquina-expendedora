#include<stdio.h>
#include<Windows.h>

struct Tproductos{
	char nombre[50];
	float coste;
	int stock;
};

int main(){
	
	FILE*pfichero;
	struct Tproductos maqexp[20];
	char eleccion_operacion, eleccion_productos, deseo_compra,deseo_operacion,cliente;
	int nproductos=0,i,nmaxclientes=10;
	float precio=0.0, pago_introducido, pago_total=0.0, vuelta=0.0;
	
	pfichero=fopen("productos.txt", "r");
	
	if (pfichero == NULL) {
		printf("No se encuentra el fichero\n");
		return 0;
	}
	
	while(fscanf(pfichero, "%s %f %i", maqexp[nproductos].nombre, &maqexp[nproductos].coste, &maqexp[nproductos].stock)!=EOF){
		nproductos++;
	}
	fclose(pfichero);
	do{
	do{	
		printf("Bienvenido\nSeleccione la operacion que desee realizar:\n");
		printf("'C' para comprar\n'P' para pagar\n'S' para ver su carro actual\n'N' para ninguna\n");
		fflush(stdin);
		scanf("%c",&eleccion_operacion);
		system("cls");
		
		if ((eleccion_operacion == 'C') || (eleccion_operacion == 'c')){
			printf("Ha seleccionado comprar. Seleccione el producto deseado:\n\n");
			do{
				for(i=0;i<nproductos;i++){
					printf("\t%s\t", maqexp[i].nombre);
					if(maqexp[i].coste==1){
						printf("%.2f euro\t",maqexp[i].coste);
					}else if(maqexp[i].coste<1){
						maqexp[i].coste=maqexp[i].coste*100;
						printf("%.0f centimos\t",maqexp[i].coste);
					}else{
						printf("%.2f euros\t",maqexp[i].coste);
					}
					printf("Quedan:%i\n\n",maqexp[i].stock);
				}
				printf("Volver(V)\n");
				fflush(stdin);
				scanf("%c",&eleccion_productos);
				system("cls");						
				if ((eleccion_productos == 'P') || (eleccion_productos == 'p')){
					if(maqexp[0].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[0].coste;
						maqexp[0].stock--;
					}
				}
				else if((eleccion_productos == 'C') || (eleccion_productos == 'c')){
					if(maqexp[1].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[1].coste;
						maqexp[1].stock--;
					}
				}
				else if((eleccion_productos == 'N') || (eleccion_productos == 'n')){
					if(maqexp[2].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[2].coste;
						maqexp[2].stock--;
					}
				}
				else if((eleccion_productos == 'O') || (eleccion_productos == 'o')){
					if(maqexp[3].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[3].coste;
						maqexp[3].stock--;
					}
				}
				else if((eleccion_productos == 'A') || (eleccion_productos == 'a')){
					if(maqexp[4].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[4].coste;
						maqexp[4].stock--;
					}
				}
				else if((eleccion_productos == 'S') || (eleccion_productos == 's')){
					if(maqexp[5].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[5].coste;
						maqexp[5].stock--;
					}
				}
				else if((eleccion_productos == 'H') || (eleccion_productos == 'h')){
					if(maqexp[6].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[6].coste;
						maqexp[6].stock--;
					}
				}
				else if((eleccion_productos == 'Q') || (eleccion_productos == 'q')){
					if(maqexp[7].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[7].coste;
						maqexp[7].stock--;
					}
				}
				else if((eleccion_productos == 'B') || (eleccion_productos == 'b')){
					if(maqexp[8].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[8].coste;
						maqexp[8].stock--;
					}
				}
				else if((eleccion_productos == 'K') || (eleccion_productos == 'k')){
					if(maqexp[9].stock==0){
						printf("Agotado\n");
						break;
					}else{
						precio+=maqexp[9].coste;
						maqexp[9].stock--;
					}
				}else if((eleccion_productos == 'V') || (eleccion_productos == 'v')){
					break;
				}
				else{
					printf("Esa letra no corresponde a ningun producto\nSeleccione otro producto\n");
				}
				fflush(stdin);
				printf("Desea comprar algun otro producto?\n'S' para si\n'N' para no\n");
				scanf("%c",&deseo_compra);
				system("cls");
			}while ((deseo_compra != 'N') && (deseo_compra != 'n'));
		}
	
	
		if((eleccion_operacion == 'S')||(eleccion_operacion == 's')){
			printf("Su carro actual es:\n-Palmeras:%i\n-Conchas:%i\n-Napolitanas:%i\n-Coca colas:%i\n-Aguas:%i\n-Sanwiches:%i\n-Haribo:%i\n-Aquarius:%i\n-Bocata:%i\n-KitKat:%i\n",10-maqexp[0].stock--, 10-maqexp[1].stock--, 10-maqexp[2].stock--, 10-maqexp[3].stock--, 10-maqexp[4].stock--, 10-maqexp[5].stock--, 10-maqexp[6].stock--, 10-maqexp[7].stock--, 10-maqexp[8].stock--, 10-maqexp[9].stock--);
		}
	
		if((eleccion_operacion == 'P') || (eleccion_operacion == 'p')){
			if(precio==0){
				printf("No has comprado nada\n");
			}else{
				printf("\n\nCantidad a introducir:%.2f\n",precio);
				while(pago_total<precio){
					printf("Introduzca el dinero\n");
					fflush(stdin);
					scanf("%f",&pago_introducido);
					pago_total+=pago_introducido;
				}
				vuelta=pago_total-precio;
				printf("Su vuelta es: %.2f\n",vuelta);
				printf("Gracias!\n");
				printf("HASTA LA PROXIMA!");
				break;
			}
			
			
		}if((eleccion_operacion== 'N') || (eleccion_operacion =='n')){
			break;
		}
		if((eleccion_operacion != 'C') && (eleccion_operacion != 'c') && (eleccion_operacion != 'S') && (eleccion_operacion != 's') && (eleccion_operacion != 'P') && (eleccion_operacion != 'p') && (eleccion_operacion != 'N') && (eleccion_operacion != 'n')){
			printf("Esa letra no corresponde a ninguna operacion\n");
		}
		printf("Desea realizar alguna otra operacion?\n");
		fflush(stdin);
		scanf("%c",&deseo_operacion);
		system("cls");
	
	}while((deseo_operacion != 'N') && (deseo_operacion != 'n'));
	
	if(pago_total<precio){
		printf("Cantidad a introducir:%.2f euros\n", precio);
		while(pago_total<precio){
			printf("Introduzca el dinero\n");
			fflush(stdin);
			scanf("%f", &pago_introducido);
			pago_total+=pago_introducido;
			system("cls");
		}
		vuelta=pago_total-precio;
		printf("Su vuelta es: %.2f euros\n",vuelta);
	}
	
	printf("Gracias!\n");
	printf("HASTA LA PROXIMA!\t");
	
	Sleep(5000);
	system("cls");
	printf("Algun otro cliente?\n'N' si no hay\nCualquier otro caracter si hay\n");
	fflush(stdin);
	scanf("%c",&cliente);
	system("cls");
	
	}while((cliente != 'N')&&(cliente != 'n'));
	
	system("cls");
	printf("Apagando...");
	Sleep(2000);
	return 0;
}
