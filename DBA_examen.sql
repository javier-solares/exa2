create database examen;
use examen;
create table productos(
Id_productos int primary key auto_increment not null,
producto varchar(50) not null,
descripcion varchar(50)not null,
imagen varchar(50)not null,
precio_costo int not null,
precio_venta  int not null,
existencia int not null,
fecha_ingres datetime not null
);
insert into productos (producto,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingres)
values ('caja de leche','bebible','imagen1','10','15','200',current_time());
values ('cereal chocolate','comestible','imagen2','11','20','150',current_time());
values ('jugos de lata','bebible','imagen3','2','4','200',current_time());
select*from productos;
create table marcas(
Id_marca int primary key auto_increment not null,
Id_productos int,constraint FK_Id_productos foreign key (Id_productos)references productos(Id_productos),
marca varchar(50) not null
);
insert into marcas (Id_productos,marca)values('1','corona');
values('2','chocokrispi');
values('3','frutal');
select *from productos;
delete producto from productos;
show tables;