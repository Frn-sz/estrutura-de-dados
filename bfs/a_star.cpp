#include <iostream> // std::cout
#include <list>     // std::list
#include <string>   // std::to_string
#include <chrono>   // usado no sleep
#include <thread>   // usado no sleep

using namespace std;

// Constantes para configurar a simulação
const int ROWS = 15; // Altura.
const int COLS = 60; // Largura.
const int WAIT = 10; // Delay da animação em ms.
const int USE_H = 1; // Usa heurística? 0=amplitude, 1=a*
const int WALL = 1;  // Usa paredes? 0=nao, 1=sim

// Classe para guardar uma coordenada e o pai dela.
class Pos
{
public:
  int x;
  int y;
  Pos *last;

  int g; // custo atual
  int h; // custo heuristico
  int f; // custo total

  Pos(int y, int x, Pos *last)
  {
    this->x = x;
    this->y = y;
    this->last = last;
  }
};

// Protótipos
void a_star(char map[ROWS][COLS], Pos *start, Pos *goal);
void bfs(char map[ROWS][COLS], Pos *start, Pos *goal);
void check_lists(list<Pos *> &open, list<Pos *> &closed, Pos *temp);
void print_map(char map[ROWS][COLS]);
void print_char(int y, int x, const std::string &c);

int main()
{
  // Cria o mapa e preenche com espaços vazios
  char map[ROWS][COLS];
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      map[i][j] = ' ';

  // Cria algumas paredes/obstaculos
  if (WALL)
  {
    for (int i = 0; i < ROWS - 3; i++)
      map[i][COLS / 3] = '#';
    for (int i = 3; i < ROWS; i++)
      map[i][COLS / 2] = '#';
    for (int i = 3; i < 6; i++)
      for (int j = COLS - 9; j < COLS - 3; j++)
        map[i][j] = '#';
  }

  // Define o ponto de partida e ponto de chegada
  Pos *start = new Pos(5, 5, nullptr);
  start->g = 0;
  Pos *goal = new Pos(ROWS - 6, COLS - 6, nullptr);

  // Escreve o mapa e escreve os chars para representarem o "start" e "goal"
  print_map(map);
  print_char(start->y, start->x, "S");
  print_char(goal->y, goal->x, "G");

  a_star(map, start, goal);

  // Done.
}

void a_star(char map[ROWS][COLS], Pos *start, Pos *goal)
{
  // Cria duas listas encadeadas, open (fila com coords a analisar) e closed (já analisados)
  list<Pos *> open, closed;

  // Insere o start na lista aberta.
  open.push_back(start);

  // Laço de busca. Repete enquanto houverem elementos na lista aberta.
  // Se a lista aberta esvaziar, então não há caminho válido.
  while (!open.empty())
  {
    // Tira o elemento com menor f da lista open
    auto smallest = open.begin();
    for (auto it = open.begin(); it != open.end(); ++it)
    {
      if ((*it)->f < (*smallest)->f)
      {
        smallest = it;
      }
    }
    Pos *current = *smallest;
    open.erase(smallest);

    // Cordenada atual é a coordenada destino?
    if (current->x == goal->x && current->y == goal->y)
    {
      current = current->last; // Volta um passo para não escrever em cima do 'G'.
      print_map(map);          // Limpa o mapa
      print_char(start->y, start->x, "S");
      print_char(goal->y, goal->x, "G");

      // Percorre o caminho encontrado do goal ao start, escrevendo *'s
      while (current != start)
      {
        print_char(current->y, current->x, "•");
        current = current->last;
      }
      break;
    }

    // Escreve um ? para mostrar que a coordenada foi analisada.
    if (current != start)
    {
      print_char(current->y, current->x, "○");
    }

    // Atual não é o destino. Pendura na lista fechada e gera novos estados.
    closed.push_back(current);

    if (current->y > 0 && map[current->y - 1][current->x] == ' ')
    {
      Pos *temp = new Pos(current->y - 1, current->x, current);
      temp->g = current->g + 1;
      temp->h = (USE_H) ? abs(temp->x - goal->x) + abs(temp->y - goal->y) : 0;
      temp->f = temp->g + temp->h;
      check_lists(open, closed, temp);
    }
    if (current->y < ROWS - 1 && map[current->y + 1][current->x] == ' ')
    {
      Pos *temp = new Pos(current->y + 1, current->x, current);
      temp->g = current->g + 1;
      temp->h = (USE_H) ? abs(temp->x - goal->x) + abs(temp->y - goal->y) : 0;
      temp->f = temp->g + temp->h;
      check_lists(open, closed, temp);
    }
    if (current->x > 0 && map[current->y][current->x - 1] == ' ')
    {
      Pos *temp = new Pos(current->y, current->x - 1, current);
      temp->g = current->g + 1;
      temp->h = (USE_H) ? abs(temp->x - goal->x) + abs(temp->y - goal->y) : 0;
      temp->f = temp->g + temp->h;
      check_lists(open, closed, temp);
    }
    if (current->x < COLS - 1 && map[current->y][current->x + 1] == ' ')
    {
      Pos *temp = new Pos(current->y, current->x + 1, current);
      temp->g = current->g + 1;
      temp->h = (USE_H) ? abs(temp->x - goal->x) + abs(temp->y - goal->y) : 0;
      temp->f = temp->g + temp->h;
      check_lists(open, closed, temp);
    }
  }

  // Final da execução. Limpa as listas.
  for (auto pos : open)
  {
    delete pos;
  }
  for (auto pos : closed)
  {
    delete pos;
  }
}

// Função que verifica se uma coordenada já se encontra em uma lista.
// Adiciona na lista aberta se for uma coord. inédita, caso contrário descarta.
void check_lists(list<Pos *> &open, list<Pos *> &closed, Pos *temp)
{
  for (auto it = open.begin(); it != open.end(); ++it)
  {
    if (temp->x == (*it)->x && temp->y == (*it)->y)
    {
      delete temp;
      return;
    }
  }

  for (auto it = closed.begin(); it != closed.end(); ++it)
  {
    if (temp->x == (*it)->x && temp->y == (*it)->y)
    {
      delete temp;
      return;
    }
  }

  open.push_front(temp);
}

// Função que escreve a matriz na tela com uma moldura ao redor.
void print_map(char map[ROWS][COLS])
{
  cout << "\033[2J\033[H";
  cout << "╔";
  for (int i = 0; i < COLS; ++i)
  {
    cout << "═";
  }
  cout << "╗" << endl;

  for (int i = 0; i < ROWS; ++i)
  {
    cout << "║";
    for (int j = 0; j < COLS; ++j)
    {
      if (map[i][j] == '#')
        cout << "\u2588";
      else
        cout << map[i][j];
    }
    cout << "║" << endl;
  }

  cout << "╚";
  for (int i = 0; i < COLS; ++i)
  {
    cout << "═";
  }
  cout << "╝" << endl
       << endl;
}

// Bruxaria que move o cursor para uma posição específica do terminal e escreve um char.
// Aguarda uma quantidade de milisegundos para fazer uma animação.
void print_char(int y, int x, const std::string &c)
{
  // move o cursor para a posição desejada
  cout << "\033[H\033[" + to_string(y + 1) + "B\033[" + to_string(x + 1) + "C";
  cout << c;

  // move o cursor pro fim
  cout << "\033[H\033[" + to_string(ROWS + 2) + "B";

  std::this_thread::sleep_for(std::chrono::milliseconds(WAIT));

  /*
  Como mover o cursor do terminal:
  \033[{n}A moves the cursor up n rows.
  \033[{n}B moves the cursor down n rows.
  \033[{n}C moves the cursor right n columns.
  \033[{n}D moves the cursor left n columns.
  \033[{row};{col}H moves the cursor to the specified row and column.
  */
}