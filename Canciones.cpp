#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct cancion
{
    string Titulo;
    string Cantante;
    string Genero;
    int Duracion;
};
typedef struct cancion Cancion;

struct album
{
    queue<Cancion> lista_feliz;
    queue<Cancion> lista_triste;
    queue<Cancion> lista_estudiosa;
};
typedef struct album Album;
Album MusicAlbum, tmp ,empt;

void menudefeliz();
void menudetriste();
void menudeestudiosa();
void agregar();
void consultar();
void vaciarcompleta();
void leertodalaplaylist();
int albumindex;

int main()
{
    //00183320 CARLOS EDUARDO NUÑEZ URRUTIA

    bool continuar = true;
    do
    {
        albumindex = 0;

        int opcion = 0;
        cout << "\n  Bienvenido a tu Album de Musica  \n";
        cout << "-----------------------------------";
        cout << "\n1) Entrar a Playlist Feliz\n";
        cout << "2) Entrar a Playlist Triste\n";
        cout << "3) Entrar a Playlist Estudiosa\n";
        cout << "4) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            menudefeliz();
            albumindex = 1;
            break;
        case 2:
            menudetriste();
            albumindex = 2;
            break;
        case 3:
            menudeestudiosa();
            albumindex = 3;
            break;
        case 4:
            continuar = false;
            break;
        default:
            cout << "Opcion invalida!\n";
            break;
        }
    } while (continuar);

    return 0;
}

void menudefeliz()
{
      albumindex = 1;
    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "\n   Playlist Feliz  \n";
        cout << "------------------------";
        cout << "\n1) Agregar nueva Cancion\n";
        cout << "2) Eliminar Cancion de la Lista\n";
        cout << "3) Vaciar Playlist\n";
        cout << "4) Mostrar Canciones de Playlist\n";
        cout << "5) Regresar a Album Inicial.\n";
        cout << "Opcion elegida: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            agregar();
            break;
        case 2:
            consultar();
            break;
        case 3:
            vaciarcompleta();
            break;
        case 4:
            leertodalaplaylist();
            break;
        case 5:
            continuar = false;
            break;
        default:
            cout << "Opcion invalida!\n";
            break;
        }
    } while (continuar);
}

void menudetriste()
{
      albumindex = 2;
    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "\n   Playlist Triste  \n";
        cout << "------------------------";
        cout << "\n1) Agregar nueva Cancion\n";
        cout << "2) Eliminar Cancion de la Lista\n";
        cout << "3) Vaciar Playlist\n";
        cout << "4) Mostrar Canciones de Playlist\n";
        cout << "5) Regresar a Album Inicial.\n";
        cout << "Opcion elegida: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            agregar();
            break;
        case 2:
            consultar();
            break;
        case 3:
            vaciarcompleta();
            break;
        case 4:
            leertodalaplaylist();
            break;
        case 5:
            continuar = false;
            break;
        default:
            cout << "Opcion invalida!\n";
            break;
        }
    } while (continuar);
}

void menudeestudiosa()
{
      albumindex = 3;
    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "\n   Playlist Estudiosa  \n";
        cout << "------------------------";
        cout << "\n1) Agregar nueva Cancion\n";
        cout << "2) Eliminar Cancion de la Lista\n";
        cout << "3) Vaciar Playlist\n";
        cout << "4) Mostrar Canciones de Playlist\n";
        cout << "5) Regresar a Album Inicial.\n";
        cout << "Opcion elegida: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            agregar();
            break;
        case 2:
            consultar();
            break;
        case 3:
            vaciarcompleta();
            break;
        case 4:
            leertodalaplaylist();
            break;
        case 5:
            continuar = false;
            break;
        default:
            cout << "Opcion invalida!\n";
            break;
        }
    } while (continuar);
}

void agregar()
{

    // Solicitar datos del trabajo
    Cancion cancioncita;
    cout << "Titulo: ";
    getline(cin, cancioncita.Titulo);
    cout << "Cantante: ";
    getline(cin, cancioncita.Cantante);
    cout << "Genero: ";
    cin >> cancioncita.Genero;
   // cin.ignore();
    
    cancioncita.Duracion = 0;
    while (cancioncita.Duracion < 1)
    {
        cout << "Duracion (Segundos): ";
       cin >> cancioncita.Duracion;
    }
    
    cin.ignore();

    switch (albumindex)
    {
    case 1:
        // Agregar a la PlayList
        MusicAlbum.lista_feliz.push(cancioncita);

        break;
    case 2:
        // Agregar a la PlayList
        MusicAlbum.lista_triste.push(cancioncita);
        break;
    case 3:
        // Agregar a la PlayList
        MusicAlbum.lista_estudiosa.push(cancioncita);
        break;

    default:
        break;
    }
}

void consultar()
{
    //ELIMINAR PRIMERA CANCION DE LA PLAYLIST
    switch (albumindex)
    {
    case 1:
        if (!MusicAlbum.lista_feliz.empty())
        {
           cout << "\n-------------------------------------------------------------------------------------------\n";
            // Ver la primera cancion de la playlist
            Cancion cancioneliminada = MusicAlbum.lista_feliz.front();
            cout << "Acabas de eliminar la Cancion : " << cancioneliminada.Titulo << "      Del Cantante: " << cancioneliminada.Cantante << endl;
            // Sacandola
            MusicAlbum.lista_feliz.pop();
        }
        else
        {
            cout << "Playlist Vacia." << endl;
        }

        break;
    case 2:
        // Eliminar
        if (!MusicAlbum.lista_triste.empty())
        {
            cout << "\n-------------------------------------------------------------------------------------------\n";
            // Ver la primera cancion de la playlist
            Cancion cancioneliminada = MusicAlbum.lista_triste.front();
               cout << "Acabas de eliminar la Cancion : " << cancioneliminada.Titulo << "      Del Cantante: " << cancioneliminada.Cantante << endl;
            // Sacandola
            MusicAlbum.lista_triste.pop();
        }
        else
        {
            cout << "Playlist Vacia." << endl;
        }
        break;
    case 3:
        // Eliminar
        if (!MusicAlbum.lista_estudiosa.empty())
        {
            cout << "\n-------------------------------------------------------------------------------------------\n";
            // Ver la primera cancion de la playlist
            Cancion cancioneliminada = MusicAlbum.lista_estudiosa.front();
              cout << "Acabas de eliminar la Cancion : " << cancioneliminada.Titulo << "      Del Cantante: " << cancioneliminada.Cantante << endl;
            // Sacandola
            MusicAlbum.lista_estudiosa.pop();
        }
        else
        {
            cout << "Playlist Vacia." << endl;
        }
        break;

    default:
        break;
    }
}

void vaciarcompleta()
{
    //ELIMINAR PRIMERA CANCION DE LA PLAYLIST
    switch (albumindex)
    {
    case 1:
        while (!MusicAlbum.lista_feliz.empty())
        {
            MusicAlbum.lista_feliz.pop();
        }

        cout << "Playlist Vaciada." << endl;

        break;
    case 2:
        // Eliminar
        while (!MusicAlbum.lista_triste.empty())
        {

            MusicAlbum.lista_triste.pop();
        }

        cout << "Playlist Vaciada." << endl;

        break;
    case 3:
        // Eliminar
        while (!MusicAlbum.lista_estudiosa.empty())
        {

            MusicAlbum.lista_estudiosa.pop();
        }

        cout << "Playlist Vaciada." << endl;

        break;

    default:
        break;
    }
}

void leertodalaplaylist()
{
      //backup
        tmp = MusicAlbum;
    //ELIMINAR PRIMERA CANCION DE LA PLAYLIST
    switch (albumindex)
    {
      
    case 1:
        while (!MusicAlbum.lista_feliz.empty())
        {
            cout << "\n-------------------------------------------------------------------------------------------\n";
            // Ver la primera cancion de la playlist
            Cancion cancioneliminada = MusicAlbum.lista_feliz.front();
            cout << "   Titulo: " << cancioneliminada.Titulo << "      Cantante: " << cancioneliminada.Cantante << "   Genero: " << cancioneliminada.Genero << "    Duracion: " << cancioneliminada.Duracion << endl;
            // Sacandola
            MusicAlbum.lista_feliz.pop();
        }

        cout << "-------------------------------------------------------------------------------------------";

        break;
    case 2:
        // Eliminar
        while (!MusicAlbum.lista_triste.empty())
        {
             cout << "\n-------------------------------------------------------------------------------------------\n";

            // Ver la primera cancion de la playlist
            Cancion cancioneliminada = MusicAlbum.lista_triste.front();
            cout << "Song |  " << cancioneliminada.Titulo << " De " << cancioneliminada.Cantante << " Genero:" << cancioneliminada.Genero << " Duracion:" << cancioneliminada.Duracion << endl;
            // Sacandola
            MusicAlbum.lista_triste.pop();
        }

       cout << "-------------------------------------------------------------------------------------------";

        break;
    case 3:
        // Eliminar
        while (!MusicAlbum.lista_estudiosa.empty())
        {
            cout << "\n-------------------------------------------------------------------------------------------\n";
            // Ver la primera cancion de la playlist
            Cancion cancioneliminada = MusicAlbum.lista_estudiosa.front();
            cout << "Song |  " << cancioneliminada.Titulo << " De " << cancioneliminada.Cantante << " Genero:" << cancioneliminada.Genero << " Duracion:" << cancioneliminada.Duracion << endl;
            // Sacandola
            MusicAlbum.lista_estudiosa.pop();
        }

    cout << "-------------------------------------------------------------------------------------------";

        break;

    default:
        cout << "Algo Salio mal con los index";
        break;
    }

    //rebackup
    MusicAlbum = tmp;

}
