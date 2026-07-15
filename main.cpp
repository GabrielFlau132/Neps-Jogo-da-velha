#include <iostream>
#include <map>
using namespace std;

void printTabuleiro(string tabuleiro[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << " " << tabuleiro[i][j];
      if (j < 2)
        cout << " |";
    }
    cout << endl;
    if (i < 2)
      cout << "-----------" << endl;
  }
  cout << endl;
}

int main()
{
  map<int, pair<int, int>> posicoes = {
      {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}}, {4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}}, {7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}}};

  while (true)
  {
    string tabuleiro[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
    int vencedor = 0;
    int disponiveis = 9;
    int jogador = 1;

    while (vencedor == 0)
    {
      printTabuleiro(tabuleiro);
      string simb = (jogador == 1) ? "X" : "O";

      int pos;
      cout << "Jogador " << jogador << " (" << simb << ") escolha uma posição: ";
      cin >> pos;
      cout << endl;

      if (posicoes.find(pos) == posicoes.end())
      {
        cout << "Posição inválida! Escolha um número de 1 a 9." << endl;
        continue;
      }

      int x = posicoes[pos].first;
      int y = posicoes[pos].second;

      if (tabuleiro[x][y] == "X" || tabuleiro[x][y] == "O")
      {
        cout << "Posição já ocupada! Escolha outra posição." << endl;
        continue;
      }

      tabuleiro[x][y] = simb;
      disponiveis--;

      printTabuleiro(tabuleiro);

      if ((tabuleiro[0][0] == simb && tabuleiro[0][1] == simb && tabuleiro[0][2] == simb) ||
          (tabuleiro[1][0] == simb && tabuleiro[1][1] == simb && tabuleiro[1][2] == simb) ||
          (tabuleiro[2][0] == simb && tabuleiro[2][1] == simb && tabuleiro[2][2] == simb) ||
          (tabuleiro[0][0] == simb && tabuleiro[1][0] == simb && tabuleiro[2][0] == simb) ||
          (tabuleiro[0][1] == simb && tabuleiro[1][1] == simb && tabuleiro[2][1] == simb) ||
          (tabuleiro[0][2] == simb && tabuleiro[1][2] == simb && tabuleiro[2][2] == simb) ||
          (tabuleiro[0][0] == simb && tabuleiro[1][1] == simb && tabuleiro[2][2] == simb) ||
          (tabuleiro[0][2] == simb && tabuleiro[1][1] == simb && tabuleiro[2][0] == simb))
      {
        vencedor = jogador;
        cout << "Parabéns! Jogador " << jogador << " venceu!" << endl;
      }
      else if (disponiveis == 0)
      {
        vencedor = -1;
        cout << "Empate! Nenhum jogador venceu." << endl;
      }

      if (vencedor == 0)
        jogador = (jogador == 1) ? 2 : 1;
    }

    char reiniciar;
    while (true)
    {
      cout << "Deseja reiniciar o jogo? (S/N): ";
      cin >> reiniciar;
      if (reiniciar == 'S' || reiniciar == 's' || reiniciar == 'N' || reiniciar == 'n')
        break;
    }

    if (reiniciar == 'N' || reiniciar == 'n')
    {
      cout << "Obrigado por jogar!" << endl;
      break;
    }
  }

  return 0;
}
