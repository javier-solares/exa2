#include<stdlib.h>
#include <iostream>
#include<mysql.h>
#include<string.h>
using namespace std;
int q_estado;
MYSQL_ROW fila;
MYSQL_RES * resultado;
MYSQL* conectar;


 int main()
{
	 
	 int opciones;
	 cout << "-----MENU-----\n" << endl;
	 cout << "1. INGRESAR DATOS" << endl;
	 cout << "2.VER DATOS" << endl;
	 cout << "3.ELIMINAR DATOS"<<endl;
	 cout << "4. VER DATOS ACTUALIZADOS" << endl;
	 cout << "5. salir\n" << endl;
	 cin >> opciones;
					
					 conectar = mysql_init(0);
					 conectar = mysql_real_connect(conectar, "localhost", "root", "root", "examen", 3382, NULL, 0);
					 string producto, descripcion, imagen, precio_costo, precio_venta, existencia;
					
					 switch (opciones)
					 {
					 case 1:
						 if (conectar) {
							 //cout << "conexion exitosa"<<endl;

							 cout << "-----Ingrese los siguientes datos-----" << endl;
							 cout << "ingrese nombre del producto" << endl;
							 cin >> producto;
							 cout << "ingrese la descripcion" << endl;
							 cin >> descripcion;
							 cout << "ingrese la imagen" << endl;
							 cin >> imagen;
							 cout << "ingrese el precio costo del producto" << endl;
							 cin >> precio_costo;
							 cout << "Ingrese el precio venta del producto" << endl;
							 cin >> precio_venta;
							 cout << "cuantos hay en existencia" << endl;
							 cin >> existencia;
							 
							 string insert = "insert into productos (producto,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingres)values('" + producto + "', '" + descripcion + "', '" + imagen + "', '" + precio_costo + "', '" + precio_venta + "', '" + existencia + "', current_time())";
							 const char* i = insert.c_str();
							 
							 //ejecuta la consulta
							 q_estado = mysql_query(conectar, i);
							 if (!q_estado) {
								 cout << "LOS DATOS SE INGRESARON EXISTOSAMENTE" << endl;
								 return main();
							 }
							 else { cout << "ERROR NO SE INGRESARON LOS DATOS" << endl; }
						 } break;
					 case 2:
						 if (!q_estado) {

							 cout << "-----DATOS DE LA TABLA----- " << endl;
							 string consul = "select*from productos";
							 const char* c = consul.c_str();
							 q_estado = mysql_query(conectar, c);
							 resultado = mysql_store_result(conectar);
							 cout << "Id_producto" << "-----" << "Producto" << "-----" << "Descripcion" << "-----" << "Imagen" << "-----" << "Precio_costo" << "-----" << "Precio_venta" << "-----" << "Existencia" << "-----" << "Fecha" << endl;
							 while (fila = mysql_fetch_row(resultado)) {

								 cout << fila[0] << "\n" << fila[1] << "\n" << fila[2] << "\n" << fila[3] << "\n" << fila[4] << "\n" << fila[5] << "\n" << fila[6] << "\n" << fila[7] << endl;
								
							 }
							 return main();
						 }break;

					 case 3:
						 if (!q_estado) {
							 cout << "-----Eliminar los datos de la tabla por su nombre-----" << endl;
							 string consuls = "delete  from productos where producto='" + producto + "'";
							 const char* d = consuls.c_str();
							 q_estado = mysql_query(conectar, d);
							 resultado = mysql_store_result(conectar);
							 cout << "ingrese el Nombre del producto para eliminarlo" << endl;
							 cin >> producto;
							 cout << "-----Datos eliminados-----" << endl;
							 return main();
						 }
						 else {
							 cout << "No se lograron eliminar los datos" << endl;
						 }break;
					 case 4:
						 if (!q_estado) {
							 cout << "-----DATOS DE LA TABLA ACTUALIZADOS-----" << endl;
							 string consultar = "select*from productos";
							 const char* n = consultar.c_str();
							 q_estado = mysql_query(conectar, n);
							 resultado = mysql_store_result(conectar);
							 while (fila = mysql_fetch_row(resultado)) {
								 cout << "Id_producto" << "-----" << "Producto" << "-----" << "Descripcion" << "-----" << "Imagen" << "-----" << "Precio_costo" << "-----" << "Precio_venta" << "-----" << "Existencia" << "-----" << "Fecha" << endl;
								 cout << fila[0] << "\n" << fila[1] << "\n" << fila[2] << "\n" << fila[3] << "\n" << fila[4] << "\n" << fila[5] << "\n" << fila[6] << "\n" << fila[7] << endl;
								 return main();

							 }
						 }break;

					 case 5:
					 		exit(1); 
					 }


						 
						 system("pause");
						 return 0;
						 
					 }
