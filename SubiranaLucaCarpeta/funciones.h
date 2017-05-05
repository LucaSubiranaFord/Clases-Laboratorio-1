typedef struct
{
    int idDueno;
    char nombre[20][50];
    char apellido[20][50];
    char apeNombre[20][100];
    char direccion[20][50];
    int tarjetaNum;
    int estado;

} eDueno;

typedef struct
{
    char patente[20][10];
    int marca;
    int idDueno;
    int horario;
    int estado;
    int salida;
} eAuto;

typedef struct
{
    int marca;
    int precio;

} eContador;


/**
 * Inicia en 0 el precio del contador
 * @param Array Contador
 * @param Tamaño del array
 */
inicializarContador(eContador[],int);




/**
 * Inicia en 0 los estados
 * @param Array auto
 * @param Array dueno
 * @param Tamaño del array
 */
inicializarEstados(eAuto[], eDueno[], int);




/**
 * Lista diferentes parametros marcados dentro del codigo
 * @param Array contador
 * @param Array auto
 * @param Array dueno
 * @param Tamaño del array
 */
listado(eContador[], eAuto[], eDueno[], int);




/**
 * Egresa un automovil
 * @param Array contador
 * @param Array dueno
 * @param Array auto
 * @param Tamaño del array
 */
egresoAutomovil(eContador[], eDueno[], eAuto[], int);




/**
 * Modifica al dueno
 * @param Array dueno
 * @param Tamaño del array
 */
modificarDueno(eDueno[], int);




/**
 * Da de alta un dueno
 * @param Array dueno
 * @param espacio libre
 * @param Tamaño del array
 */
altaDueno(eDueno[],int, int);


/**
 * Obtiene el primer espacio libre del array dueno
 * @param Array dueno
 * @param Tamaño del array
 */
int obtenerEspacioLibre(eDueno[], int);




/**
 * Obtiene el primer espacio libre del array auto
 * @param Array auto
 * @param Tamaño del array
 */
int obtenerEspacioLibreAuto(eAuto[], int);




/**
 * Muestra al dueno
 * @param Array dueno
 * @param Tamaño del array
 */
mostrarDueno(eDueno[], int);



/**
 * Da de alta un auto
 * @param Array auto
 * @param Array dueno
 * @param Espacio libre
 * @param Tamaño del array
 */
altaAuto(eAuto[], eDueno[],int, int);



/**
 * Muestra al auto
 * @param Array auto
 * @param Tamaño del array
 */
mostrarAuto(eAuto[], int);
