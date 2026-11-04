#include <iostream>
#include <math.h>
#define FILAS 200
#define COLUMNAS 200
#define VACIO -1

using namespace std;

struct Orden
{
    bool ocupado = false;

    unsigned int espera = 0;
    bool soltarGranada1 = false;
    bool soltarGranada2 = false;
    bool ataqueKamikaze = false;
    bool aterrizaje = false;
    bool despegue = false;
    int siguientex =0;
    int siguientey = 0;
};

struct OrdenArchivo
{
    bool ocupado = false;

    int x =0;
    int y =0;
    unsigned int espera = 0;
    bool soltarGranada1 = false;
    bool soltarGranada2 = false;
    bool ataqueKamikaze = false;
    bool aterrizaje = false;
    bool despegue = false;
    int siguientex =0;
    int siguientey= 0;
};

void inicializarTabla(Orden tabla[][COLUMNAS])
{
    for(int i = 0; i < FILAS; i++)
    {
        for(int j = 0; j < COLUMNAS; j++)
        {
            tabla[i][j].espera = 0;
            tabla[i][j].soltarGranada1 = false;
            tabla[i][j].soltarGranada2 = false;
            tabla[i][j].ataqueKamikaze = false;
            tabla[i][j].aterrizaje = false;
            tabla[i][j].despegue = false;
            tabla[i][j].siguientex = VACIO;
            tabla[i][j].siguientey = VACIO;
            tabla[i][j].ocupado = false;
        }
    }

};


void crearArchivo()
{
    char nombre_archivo[300];
    cout << "" << endl;
    cout << "Nombre de ruta del archivo: ";
    cin >> nombre_archivo;
    FILE *f;
    f = fopen(nombre_archivo, "wb");

    if(f != NULL)
    {
        OrdenArchivo orden; //Buffer


        int espera2;

        char decisionGranada1;

        char decisionGranada2;

        char decisionKamikaze;

        char decisionAterrizaje;

        char decisionDespegue;

        char decisionSalir;

        do
        {
            do
            {
                cout << "Posicion X [0;199]: ";
                cin >> orden.x;
                if(orden.x < 0 || orden.x >= 200)
                    cout << "Ingrese una posicion dentro de los limites" << endl;
            }
            while(orden.x < 0 || orden.x >= 200);

            do
            {
                cout << "Posicion Y [0;199]: ";
                cin >> orden.y;
                if(orden.y < 0 || orden.y >= 200)
                    cout << "Ingrese una posicion dentro de los limites" << endl;
            }
            while(orden.y < 0 || orden.y >= 200);

            do
            {
                cout << "Tiempo de espera: ";
                cin >> espera2;
                if(espera2 < 0)
                    cout << "Ingrese un tiempo positivo" << endl;
                else
                    orden.espera = espera2;
            }
            while(espera2 < 0);



            do
            {
                cout << "Soltar granada 1 (s/n): ";
                cin >> decisionGranada1;
                if(decisionGranada1 == 's')
                    orden.soltarGranada1 = true;
                else
                {
                    if(decisionGranada1 == 'n')
                        orden.soltarGranada1 = false;
                    else
                        cout << "Ingrese una opcion correcta" << endl;
                }
            }
            while(decisionGranada1 != 's' && decisionGranada1 != 'n');

            do
            {
                cout << "Soltar granada 2 (s/n): ";
                cin >> decisionGranada2;
                if(decisionGranada2 == 's')
                    orden.soltarGranada2 = true;
                else
                {
                    if(decisionGranada2 == 'n')
                        orden.soltarGranada2 = false;
                    else
                        cout << "Ingrese una opcion correcta" << endl;
                }
            }
            while(decisionGranada2 != 's' && decisionGranada2 != 'n');

            do
            {
                cout << "Ataque Kamikaze (s/n): ";
                cin >> decisionKamikaze;
                if(decisionKamikaze == 's')
                    orden.ataqueKamikaze = true;
                else
                {
                    if(decisionKamikaze == 'n')
                        orden.ataqueKamikaze = false;
                    else
                        cout << "Ingrese una opcion correcta" << endl;
                }
            }
            while(decisionKamikaze != 's' && decisionKamikaze != 'n');

            do
            {
                cout << "Aterrizaje (s/n): ";
                cin >> decisionAterrizaje;
                if(decisionAterrizaje == 's')
                    orden.aterrizaje = true;
                else
                {
                    if(decisionAterrizaje == 'n')
                        orden.aterrizaje = false;
                    else
                        cout << "Ingrese una opcion correcta" << endl;
                }
            }
            while(decisionAterrizaje != 's' && decisionAterrizaje != 'n');


            do
            {
                cout << "Despegue (s/n): ";
                cin >> decisionDespegue;
                if(decisionDespegue == 's')
                    orden.despegue = true;
                else
                {
                    if(decisionDespegue == 'n')
                        orden.despegue = false;
                    else
                        cout << "Ingrese una opcion correcta" << endl;
                }
            }
            while(decisionDespegue != 's' && decisionDespegue != 'n');

            int siguienteX;
            int siguienteY;

            do
            {
                cout << "Siguiente X [0;199]: ";
                cin >> siguienteX;
                if(siguienteX < 0 || siguienteX >= 200)
                    cout << "Ingrese una posicion dentro de los limites" << endl;
                else
                    orden.siguientex = siguienteX;
            }
            while(siguienteX < 0 || siguienteX >= 200);

            do
            {
                cout << "Siguiente Y [0;199]: ";
                cin >> siguienteY;
                if(siguienteY < 0 || siguienteY >= 200)
                    cout << "Ingrese una posicion dentro de los limites" << endl;
                else
                    orden.siguientey = siguienteY;
            }
            while(siguienteY < 0 || siguienteY >= 200);


            fwrite(&orden, sizeof(OrdenArchivo), 1, f);

            do
            {
                cout << "¿Desea agregar otro registro? (s/n): ";
                cin >> decisionSalir;

                if(decisionSalir != 's' && decisionSalir != 'n')
                    cout << "Ingrese una opcion correcta" << endl;
                else if(decisionSalir == 'n')
                {
                    fclose(f);
                    return;
                }


            }
            while(decisionSalir != 's' && decisionSalir != 'n');


        }
        while(decisionSalir != 'n');

    }
    else
        cout << "No se pudo crear el archivo" << endl;



}


void cargarArchivo(Orden tabla[][COLUMNAS], bool &huboError)
{
    inicializarTabla(tabla);
    huboError = false;

    OrdenArchivo ordenArchivo;

    Orden orden;

    char nombre_archivo[300];
    cout << "" << endl;
    cout << "Nombre de ruta del archivo: ";
    cin >> nombre_archivo;
    FILE *f;
    f = fopen(nombre_archivo, "rb");

    if(f != NULL)
    {
        int contadorDespegue = 0;

        bool despegueConAtaque = false;

        int contadorAterrizaje = 0;

        int contadorKamikaze = 0;

        int contadorMismaCoordenada = 0;

        int contadorNoAledano = 0;

        int contadorFueraDeRango = 0;


        while(fread(&ordenArchivo, sizeof(ordenArchivo), 1, f))
        {

            if(ordenArchivo.x < 0 || ordenArchivo.x >= FILAS || ordenArchivo.y < 0 || ordenArchivo.y >= COLUMNAS)
                contadorFueraDeRango++;
            else
            {
                orden.espera = ordenArchivo.espera;
                orden.soltarGranada1 = ordenArchivo.soltarGranada1;
                orden.soltarGranada2 = ordenArchivo.soltarGranada2;
                orden.ataqueKamikaze = ordenArchivo.ataqueKamikaze;
                orden.aterrizaje = ordenArchivo.aterrizaje;
                orden.despegue = ordenArchivo.despegue;
                orden.siguientex = ordenArchivo.siguientex;
                orden.siguientey = ordenArchivo.siguientey;
                orden.ocupado = ordenArchivo.ocupado;

                if(!ordenArchivo.aterrizaje && !ordenArchivo.ataqueKamikaze)
                {
                    int dx = abs(ordenArchivo.siguientex - ordenArchivo.x);
                    int dy = abs(ordenArchivo.siguientey - ordenArchivo.y);

                    if(dx > 1 || dy > 1 || (dx == 0 && dy == 0))
                    {
                        contadorNoAledano++;
                    }
                }

                if(tabla[ordenArchivo.x][ordenArchivo.y].ocupado)
                {
                    contadorMismaCoordenada++;
                }
                else
                {
                    orden.ocupado = true;
                    tabla[ordenArchivo.x][ordenArchivo.y] = orden;
                }

                if(ordenArchivo.despegue)
                    contadorDespegue += 1;

                if(ordenArchivo.despegue && (ordenArchivo.ataqueKamikaze || ordenArchivo.soltarGranada1 || ordenArchivo.soltarGranada2))
                    despegueConAtaque = true;

                if(ordenArchivo.aterrizaje)
                    contadorAterrizaje += 1;

                if(ordenArchivo.ataqueKamikaze)
                    contadorKamikaze += 1;
            }
        }

        if(contadorFueraDeRango > 0)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: Hay registros con coordenadas fuera de la tabla (0 a 199)." << endl;
            huboError = true;
        }

        if(contadorMismaCoordenada > 0)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: No se puede pasar por la misma coordenada mas de una vez." << endl;
            huboError = true;
        }

        if(contadorDespegue > 1)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: Los archivos deben tener una unica instruccion de despegue. " << endl;
            huboError = true;
        }
        if(contadorDespegue == 0)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: Debe haber un despegue" << endl;
            huboError = true;
        }

        if(despegueConAtaque)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: La instruccion de despegue no puede estar acompañada por ningún tipo de ataque." << endl;
            huboError = true;
        }

        if(contadorAterrizaje > 0 && contadorKamikaze > 0)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: Debe existir una unica instruccion de aterrizaje o ataqueKamikaze." << endl;
            huboError = true;
        }

        if(contadorAterrizaje > 1)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: Debe existir una unica instruccion de aterrizaje." << endl;
            huboError = true;
        }

        if(contadorKamikaze > 1)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: Debe existir una unica instruccion de ataqueKamikaze." << endl;
            huboError = true;
        }

        if(contadorAterrizaje == 0 && contadorKamikaze == 0)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: Debe haber un aterrizaje" << endl;
            huboError = true;
        }

        if(contadorNoAledano > 0)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: La siguiente coordenada debe ser aledaña a la coordenada actual." << endl;
            huboError = true;
        }


        //Verificamos que exista el registro con la posicion (x,y) de cada siguiente x/y que pongamos (salvo que sea aterrizaje o kamikaze)

        int contadorHueco = 0;

        for(int i = 0; i < FILAS; i++)
        {
            for(int j = 0; j < COLUMNAS; j++)
            {
                if(tabla[i][j].ocupado && !tabla[i][j].aterrizaje && !tabla[i][j].ataqueKamikaze)
                {
                    int sigx = tabla[i][j].siguientex;
                    int sigy = tabla[i][j].siguientey;

                    if(sigx < 0 || sigx >= FILAS || sigy < 0 || sigy >= COLUMNAS || !tabla[sigx][sigy].ocupado)
                    {
                        contadorHueco++;
                    }
                }
            }
        }

        if(contadorHueco > 0)
        {
            cout << "ERROR: No se pudo cargar el archivo." << endl;
            cout << "Motivo: La ruta tiene huecos (siguientex/siguientey apunta a una celda que no existe en el archivo)." << endl;
            huboError = true;
        }


        fclose(f);

        if(huboError)
            inicializarTabla(tabla);
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
        huboError = true;
    }

    return;
}

void mostrarAtaque(Orden tabla[][COLUMNAS])
{

    int contador = 0;
    cin.ignore(10000, '\n');

    for(int i = 0; i < FILAS; i++)
    {
        for(int j = 0; j < COLUMNAS; j++)
        {
            if(tabla[i][j].siguientex != VACIO && contador < 2)
            {
                cout << "X: " << i << endl;
                cout << "Y: " << j << endl;
                cout << "" << endl;
                cout << "Tiempo de espera: " << tabla[i][j].espera << endl;

                if(tabla[i][j].soltarGranada1 == true)
                    cout << "Soltar granada 1: Si" << endl;
                else
                    cout << "Soltar granada 1: No" << endl;

                if(tabla[i][j].soltarGranada2 == true)
                    cout << "Soltar granada 2: Si" << endl;
                else
                    cout << "Soltar granada 2: No" << endl;

                if(tabla[i][j].ataqueKamikaze == true)
                    cout << "Ataque Kamikaze: Si" << endl;
                else
                    cout << "Ataque Kamikaze: No" << endl;

                if(tabla[i][j].aterrizaje == true)
                    cout << "Aterrizaje: Si" << endl;
                else
                    cout << "Aterrizaje: No" << endl;

                if(tabla[i][j].despegue == true)
                    cout << "Despegue: Si" << endl;
                else
                    cout << "Despegue: No" << endl;

                cout << "Siguiente X: " << tabla[i][j].siguientex << endl;
                cout << "Siguiente Y: " << tabla[i][j].siguientey << endl;
                cout << "" << endl;

                contador++;

                if(contador == 2)
                {
                    cout << "Presione Enter para seguir viendo" << endl;
                    int entradaUsuario = getchar();
                    if(entradaUsuario == 10)
                        contador = 0;
                }
            }

        }

    }


}

void corregirRegistroArchivo()
{
    int espera2;

    char decisionGranada1;

    char decisionGranada2;

    char decisionKamikaze;

    char decisionAterrizaje;

    char decisionDespegue;


    cout << "" << endl;

    char nombre_archivo[300];
    cout << "Ruta y Nombre del archivo a corregir: ";
    cin >> nombre_archivo;
    FILE *f;
    f = fopen(nombre_archivo, "rb");

    if(f!= NULL)
    {
        int x;
        int y;

        cout << "Posicion X: ";
        cin >> x;
        cout << "Posicion Y: ";
        cin >> y;

        OrdenArchivo orden;

        OrdenArchivo *registros = new OrdenArchivo[FILAS * COLUMNAS];

        int cantidad = 0;
        bool encontrado = false;

        while(fread(&orden, sizeof(OrdenArchivo), 1, f))
        {
            if(orden.x == x && orden.y == y)
            {
                encontrado = true;

                cout << "" << endl;
                cout << "Posicion X: " << orden.x << endl;
                cout << "Posicion Y: " << orden.y << endl;
                cout << "Tiempo de espera: " << orden.espera << endl;

                if(orden.soltarGranada1 == true)
                    cout << "Soltar granada 1: Si" << endl;
                else
                    cout << "Soltar granada 1: No" << endl;

                if(orden.soltarGranada2 == true)
                    cout << "Soltar granada 2: Si" << endl;
                else
                    cout << "Soltar granada 2: No" << endl;

                if(orden.ataqueKamikaze == true)
                    cout << "Ataque Kamikaze: Si" << endl;
                else
                    cout << "Ataque Kamikaze: No" << endl;

                if(orden.aterrizaje == true)
                    cout << "Aterrizaje: Si" << endl;
                else
                    cout << "Aterrizaje: No" << endl;

                if(orden.despegue == true)
                    cout << "Despegue: Si" << endl;
                else
                    cout << "Despegue: No" << endl;

                cout << "Siguiente X: " << orden.siguientex << endl;
                cout << "Siguiente Y: " << orden.siguientey << endl;
                cout << "" << endl;


                do
                {
                    cout << "Tiempo de espera: ";
                    cin >> espera2;
                    if(espera2 < 0)
                        cout << "Ingrese un tiempo positivo" << endl;
                    else
                        orden.espera = espera2;
                }
                while(espera2 < 0);

                do
                {
                    cout << "Soltar granada 1 (s/n): ";
                    cin >> decisionGranada1;
                    if(decisionGranada1 == 's')
                        orden.soltarGranada1 = true;
                    else
                    {
                        if(decisionGranada1 == 'n')
                            orden.soltarGranada1 = false;
                        else
                            cout << "Ingrese una opcion correcta" << endl;
                    }
                }
                while(decisionGranada1 != 's' && decisionGranada1 != 'n');

                do
                {
                    cout << "Soltar granada 2 (s/n): ";
                    cin >> decisionGranada2;
                    if(decisionGranada2 == 's')
                        orden.soltarGranada2 = true;
                    else
                    {
                        if(decisionGranada2 == 'n')
                            orden.soltarGranada2 = false;
                        else
                            cout << "Ingrese una opcion correcta" << endl;
                    }
                }
                while(decisionGranada2 != 's' && decisionGranada2 != 'n');

                do
                {
                    cout << "Ataque Kamikaze (s/n): ";
                    cin >> decisionKamikaze;
                    if(decisionKamikaze == 's')
                        orden.ataqueKamikaze = true;
                    else
                    {
                        if(decisionKamikaze == 'n')
                            orden.ataqueKamikaze = false;
                        else
                            cout << "Ingrese una opcion correcta" << endl;
                    }
                }
                while(decisionKamikaze != 's' && decisionKamikaze != 'n');

                do
                {
                    cout << "Aterrizaje (s/n): ";
                    cin >> decisionAterrizaje;
                    if(decisionAterrizaje == 's')
                        orden.aterrizaje = true;
                    else
                    {
                        if(decisionAterrizaje == 'n')
                            orden.aterrizaje = false;
                        else
                            cout << "Ingrese una opcion correcta" << endl;
                    }
                }
                while(decisionAterrizaje != 's' && decisionAterrizaje != 'n');


                do
                {
                    cout << "Despegue (s/n): ";
                    cin >> decisionDespegue;
                    if(decisionDespegue == 's')
                        orden.despegue = true;
                    else
                    {
                        if(decisionDespegue == 'n')
                            orden.despegue = false;
                        else
                            cout << "Ingrese una opcion correcta" << endl;
                    }
                }
                while(decisionDespegue != 's' && decisionDespegue != 'n');

                int siguienteX;
                int siguienteY;

                do
                {
                    cout << "Siguiente X [0;199]: ";
                    cin >> siguienteX;
                    if(siguienteX < 0 || siguienteX >= 200)
                        cout << "Ingrese una posicion dentro de los limites" << endl;
                    else
                        orden.siguientex = siguienteX;
                }
                while(siguienteX < 0 || siguienteX >= 200);

                do
                {
                    cout << "Siguiente Y [0;199]: ";
                    cin >> siguienteY;
                    if(siguienteY < 0 || siguienteY >= 200)
                        cout << "Ingrese una posicion dentro de los limites" << endl;
                    else
                        orden.siguientey = siguienteY;
                }
                while(siguienteY < 0 || siguienteY >= 200);

                registros[cantidad] = orden;
                cantidad++;

            }
            else
            {
                registros[cantidad] = orden;
                cantidad++;
            }
        }

        fclose(f);

        if(!encontrado)
        {
            cout << "No se encontro ningun registro en esa posicion" << endl;

            delete[] registros;
            return;
        }

        f = fopen(nombre_archivo, "wb");

        if(f != NULL)
        {
            fwrite(registros, sizeof(OrdenArchivo), cantidad, f);
            fclose(f);

            cout << "Registro corregido" << endl;
        }
        else
            cout << "No se pudo abrir el archivo" << endl;


        delete[] registros;
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }

    return;

}

void corregirRegistroMemoria(Orden tabla[][COLUMNAS])
{
    int x;
    int y;
    cout << "Posicion X: ";
    cin >> x;
    cout << "Posicion Y: ";
    cin >> y;

    bool encontrado = false;

    int espera;
    char decisionGranada1;
    char decisionGranada2;
    char decisionKamikaze;
    char decisionAterrizaje;
    char decisionDespegue;
    int sigx;
    int sigy;



    //Encontrar
    for(int i = 0; i < FILAS; i++)
    {
        for(int j = 0; j < COLUMNAS; j++)
        {
            if(tabla[i][j].siguientex != VACIO && tabla[i][j].siguientey != VACIO)
            {
                if(i == x && j == y)
                {
                    encontrado = true;
                    cout << "Tiempo de espera: " << tabla[i][j].espera << endl;

                    if(tabla[i][j].soltarGranada1 == true)
                        cout << "Soltar granada 1: Si" << endl;
                    else
                        cout << "Soltar granada 1: No" << endl;

                    if(tabla[i][j].soltarGranada2 == true)
                        cout << "Soltar granada 2: Si" << endl;
                    else
                        cout << "Soltar granada 2: No" << endl;

                    if(tabla[i][j].ataqueKamikaze == true)
                        cout << "Ataque Kamikaze: Si" << endl;
                    else
                        cout << "Ataque Kamikaze: No" << endl;

                    if(tabla[i][j].aterrizaje == true)
                        cout << "Aterrizaje: Si" << endl;
                    else
                        cout << "Aterrizaje: No" << endl;

                    if(tabla[i][j].despegue == true)
                        cout << "Despegue: Si" << endl;
                    else
                        cout << "Despegue: No" << endl;


                    cout << "Siguiente X: " << tabla[i][j].siguientex << endl;
                    cout << "Siguiente Y: " << tabla[i][j].siguientey << endl;

                    cout << "" << endl;

                    cout << "======Correccion======" << endl;
                    do
                    {
                        cout << "Tiempo de espera: ";
                        cin >> espera;
                        if(espera < 0)
                            cout << "Ingrese un tiempo positivo" << endl;
                        else
                            tabla[i][j].espera = espera;
                    }
                    while(espera < 0);

                    do
                    {
                        cout << "Soltar granada 1 (s/n): ";
                        cin >> decisionGranada1;
                        if(decisionGranada1 == 's')
                            tabla[i][j].soltarGranada1 = true;
                        else
                        {
                            if(decisionGranada1 == 'n')
                                tabla[i][j].soltarGranada1 = false;
                            else
                                cout << "Ingrese una opcion correcta" << endl;
                        }
                    }
                    while(decisionGranada1 != 's' && decisionGranada1 != 'n');

                    do
                    {
                        cout << "Soltar granada 2 (s/n): ";
                        cin >> decisionGranada2;
                        if(decisionGranada2 == 's')
                            tabla[i][j].soltarGranada2 = true;
                        else
                        {
                            if(decisionGranada2 == 'n')
                                tabla[i][j].soltarGranada2 = false;
                            else
                                cout << "Ingrese una opcion correcta" << endl;
                        }
                    }
                    while(decisionGranada2 != 's' && decisionGranada2 != 'n');

                    do
                    {
                        cout << "Ataque Kamikaze (s/n): ";
                        cin >> decisionKamikaze;
                        if(decisionKamikaze == 's')
                            tabla[i][j].ataqueKamikaze = true;
                        else
                        {
                            if(decisionKamikaze == 'n')
                                tabla[i][j].ataqueKamikaze = false;
                            else
                                cout << "Ingrese una opcion correcta" << endl;
                        }
                    }
                    while(decisionKamikaze != 's' && decisionKamikaze != 'n');

                    do
                    {
                        cout << "Aterrizaje (s/n): ";
                        cin >> decisionAterrizaje;
                        if(decisionAterrizaje == 's')
                            tabla[i][j].aterrizaje = true;
                        else
                        {
                            if(decisionAterrizaje == 'n')
                                tabla[i][j].aterrizaje = false;
                            else
                                cout << "Ingrese una opcion correcta" << endl;
                        }
                    }
                    while(decisionAterrizaje != 's' && decisionAterrizaje != 'n');


                    do
                    {
                        cout << "Despegue (s/n): ";
                        cin >> decisionDespegue;
                        if(decisionDespegue == 's')
                            tabla[i][j].despegue = true;
                        else
                        {
                            if(decisionDespegue == 'n')
                                tabla[i][j].despegue = false;
                            else
                                cout << "Ingrese una opcion correcta" << endl;
                        }
                    }
                    while(decisionDespegue != 's' && decisionDespegue != 'n');

                    int siguienteX;
                    int siguienteY;

                    do
                    {
                        cout << "Siguiente X [0;199]: ";
                        cin >> sigx;
                        if(sigx < 0 || sigx >= 200)
                            cout << "Ingrese una posicion dentro de los limites" << endl;
                        else
                            tabla[i][j].siguientex = sigx;
                    }
                    while(sigx < 0 || sigx >= 200);

                    do
                    {
                        cout << "Siguiente Y [0;199]: ";
                        cin >> siguienteY;
                        if(siguienteY < 0 || siguienteY >= 200)
                            cout << "Ingrese una posicion dentro de los limites" << endl;
                        else
                            tabla[i][j].siguientey = siguienteY;
                    }
                    while(siguienteY < 0 || siguienteY >= 200);


                }


            }

        }
    }

    //Corregir


    if(encontrado == false)
    {
        cout << "No se encontro un registro en esa posicion" << endl;
        return;
    }
}

void guardarMemoriaArchivoNuevo(Orden tabla[][COLUMNAS])
{
    char nombre_archivo[300];
    cout << "Ingrese nombre y ruta del archivo: ";
    cin >> nombre_archivo;
    FILE *f = fopen(nombre_archivo, "wb");


    OrdenArchivo orden;

    if(f)
    {
            for(int i = 0; i < FILAS; i++)
        {
            for(int j = 0; j < COLUMNAS; j++)
            {
                if(tabla[i][j].siguientex != VACIO)
                {
                    orden.x = i;
                    orden.y = j;
                    orden.espera = tabla[i][j].espera;
                    orden.soltarGranada1 = tabla[i][j].soltarGranada1;
                    orden.soltarGranada2 = tabla[i][j].soltarGranada2;
                    orden.ataqueKamikaze = tabla[i][j].ataqueKamikaze;
                    orden.aterrizaje = tabla[i][j].aterrizaje;
                    orden.despegue = tabla[i][j].despegue;
                    orden.siguientex = tabla[i][j].siguientex;
                    orden.siguientey = tabla[i][j].siguientey;
                    orden.ocupado = tabla[i][j].ocupado;

                    fwrite(&orden, sizeof(OrdenArchivo), 1, f);
                }

            }
        }
        fclose(f);
    }

    else
        cout << "No se pudo crear el archivo" << endl;




}

void generarHTML(Orden tabla[][COLUMNAS])
{
    char nombreArchivo[300];
    cout << "Nombre y ruta del archivo: " ;
    cin >> nombreArchivo;
    FILE *archivo;
    int fila, columna;
    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL)
    {
        printf("No se pudo crear el archivo.\n");
        return;
    }
    fprintf(archivo, "<html>\n");
    fprintf(archivo, "<head><title>Ataque</title></head>\n");
    fprintf(archivo, "<body>\n");

    //Explicacion de cada emoji
    fprintf(archivo, "<h3>&#128747;: Despegue</h3>");
    fprintf(archivo, "<h3>&#128748;: Aterrizaje</h3>");
    fprintf(archivo, "<h3>&#128163;: Soltar Granada 1</h3>");
    fprintf(archivo, "<h3>&#129512;: Soltar Granada 2</h3>");
    fprintf(archivo, "<h3>&#128165;: Ataque Kamikaze</h3>");
    fprintf(archivo, "<h3>&#9203;: Espera</h3>");
    fprintf(archivo, "<h3>&#128099;: Paso sin acción</h3>");




    fprintf(archivo, "<table border=\"1\">\n");

    fprintf(archivo, "<tr><th></th>");
    for (int x = 0; x < COLUMNAS; x++)
        fprintf(archivo, "<th>%d</th>", x);
    fprintf(archivo, "</tr>\n");

    for (fila = 0; fila < FILAS; fila++)
    {
        fprintf(archivo, "<tr>\n");
        fprintf(archivo, "<th>%d</th>", fila);
        for (columna = 0; columna < COLUMNAS; columna++)
        {

            if(tabla[fila][columna].siguientex != VACIO)
            {
                fprintf(archivo, "<td>");

                if(tabla[fila][columna].despegue)
                    fprintf(archivo, "%s", "&#128747;");
                if(tabla[fila][columna].aterrizaje)
                    fprintf(archivo, "%s", "&#128748;");
                if(tabla[fila][columna].soltarGranada1)
                    fprintf(archivo, "%s", "&#128163;");
                if(tabla[fila][columna].soltarGranada2)
                    fprintf(archivo, "%s", "&#129512;");
                if(tabla[fila][columna].ataqueKamikaze)
                    fprintf(archivo, "%s", "&#128165;");
                if(tabla[fila][columna].espera > 0)
                    fprintf(archivo, "%s", "&#9203;");

                if(
                   !tabla[fila][columna].despegue && !tabla[fila][columna].aterrizaje && !tabla[fila][columna].soltarGranada1
                   && !tabla[fila][columna].soltarGranada2 && !tabla[fila][columna].ataqueKamikaze && !tabla[fila][columna].espera > 0
                   )
                    fprintf(archivo, "%s", "&#128099;");

                fprintf(archivo, "</td>");
            }
            else
                fprintf(archivo, "<td></td>");

        }
        fprintf(archivo, "</tr>\n");
    }
    fprintf(archivo, "</table>\n");
    fprintf(archivo, "</body>\n");
    fprintf(archivo, "</html>\n");
    fclose(archivo);
}


int main()
{
    Orden tabla[FILAS][COLUMNAS];
    int opcion;
    inicializarTabla(tabla);

    bool huboError = false;
    do
    {
        cout << "=======Bienvenido al Sistema de Drones========" << endl;
        cout << "1. Cargar archivo de ataque en memoria." << endl;
        cout << "2. Mostrar ataque cargado." << endl;
        cout << "3. Crear un archivo de ataque nuevo." << endl;
        cout << "4. Corregir un registro del archivo." << endl;
        cout << "5. Corregir un registro en memoria" << endl;
        cout << "6. Guardar memoria en un archivo nuevo." << endl;
        cout << "7. Visualizar un archivo de ataque en html." << endl;
        cout << "0. Salir." << endl;

        cout << "" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;


        switch(opcion)
        {
        case 1:
            cargarArchivo(tabla, huboError);
            break;
        case 2:
            if(!huboError)
                mostrarAtaque(tabla);
            else
                cout << "No hay ningun archivo cargado" << endl;
            break;
        case 3:
            crearArchivo();
            break;
        case 4:
            corregirRegistroArchivo();
            break;
        case 5:
            corregirRegistroMemoria(tabla);
            break;
        case 6:
            guardarMemoriaArchivoNuevo(tabla);
            break;
        case 7:
            generarHTML(tabla);
            break;

        }

    }
    while(opcion != 0);

    return 0;
}

