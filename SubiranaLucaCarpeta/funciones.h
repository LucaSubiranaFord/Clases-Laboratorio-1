typedef struct
{
    int idDueno;
    char nombre[20][50];
    char apellido[20][50];
    char apeNombre[20][100];
    char direccion[20][50];
    long long tarjetaNum; //SE DECLARA LONG LONG DEBIDO A QUE LA TARJETA DEBE TENER 16 NUMEROS DE LONGITUD.
    int estado;

} eDueno;

typedef struct
{
    char patente[20][10];
    char marca[10][12];
    int idDueno;
    int horario;
    int estado;
    int salida;
    int estadoEstadia;
} eAuto;

cargarAuto(eAuto[], int[]);
cargarDueno(eDueno[]);

/**
 * Inicia en 0 el precio del contador
 * @param Array Contador
 * @param Tama�o del array
 */
inicializarContador(int[],int);




/**
 * Inicia en 0 los estados
 * @param Array auto
 * @param Array dueno
 * @param Tama�o del array
 */
inicializarEstados(eAuto[], eDueno[], int);




/**
 * Lista diferentes parametros marcados dentro del codigo
 * @param Array contador
 * @param Array auto
 * @param Array dueno
 * @param Tama�o del array
 */
listado(int[], eAuto[], eDueno[], int);




/**
 * Egresa un automovil
 * @param Array contador
 * @param Array dueno
 * @param Array auto
 * @param Tama�o del array
 */
egresoAutomovil(int[], eDueno[], eAuto[], int);




/**
 * Modifica al dueno
 * @param Array dueno
 * @param Tama�o del array
 */
modificarDueno(eDueno[], int);




/**
 * Da de alta un dueno
 * @param Array dueno
 * @param espacio libre
 * @param Tama�o del array
 */
altaDueno(eDueno[],int, int);


/**
 * Obtiene el primer espacio libre del array dueno
 * @param Array dueno
 * @param Tama�o del array
 */
int obtenerEspacioLibre(eDueno[], int);




/**
 * Obtiene el primer espacio libre del array auto
 * @param Array auto
 * @param Tama�o del array
 */
int obtenerEspacioLibreAuto(eAuto[], int);




/**
 * Muestra al dueno
 * @param Array dueno
 * @param Tama�o del array
 */
mostrarDueno(eDueno[], int);



/**
 * Da de alta un auto
 * @param Array auto
 * @param Array dueno
 * @param Espacio libre
 * @param Tama�o del array
 */
altaAuto(eAuto[], eDueno[],int, int);



/**
 * Muestra al auto
 * @param Array auto
 * @param Tama�o del array
 */
mostrarAuto(eAuto[], int);
