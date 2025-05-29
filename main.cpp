// Trabalho de Programação - BM-Bank
// Sistema de Gestão de Usuários
// Felipe Paiva - 2114521
// Gustavo Pereira - 
// Gabriel Marchiori - 


#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Usuario {
    int id;
    char nome[101];
    int idade;
    double saldo;
};

Usuario** usuarios = nullptr;
int capacidade = 0;
int totalUsuarios = 0;
int proximoId = 1;

void redimensionar() {
    capacidade = capacidade == 0 ? 10 : capacidade * 2;
    Usuario** novoArray = new Usuario*[capacidade];
    for (int i = 0; i < totalUsuarios; ++i) {
        novoArray[i] = usuarios[i];
    }
    delete[] usuarios;
    usuarios = novoArray;
}

void salvarEmArquivo(const char* nomeArquivo) {
    ofstream arq(nomeArquivo);
    if (!arq) return;
    arq << totalUsuarios << endl;
    for (int i = 0; i < totalUsuarios; ++i) {
        arq << usuarios[i]->nome << ", " << usuarios[i]->idade << "," << fixed << setprecision(2) << usuarios[i]->saldo << endl;
    }
    arq.close();
}

void inserirUsuario(const char* nome, int idade, double saldo) {
    if (saldo < 0) {
        cout << "Erro: saldo negativo nao permitido." << endl;
        return;
    }
    if (totalUsuarios >= capacidade) redimensionar();
    Usuario* u = new Usuario;
    u->id = proximoId++;
    strncpy(u->nome, nome, 100);
    u->nome[100] = '\0';
    u->idade = idade;
    u->saldo = saldo;
    usuarios[totalUsuarios++] = u;
    cout << "Usuario inserido com id " << u->id << "." << endl;
}

void inserirMultiplos(int qtd) {
    for (int i = 0; i < qtd; ++i) {
        string linha;
        getline(cin, linha);
        char nome[101]; int idade; double saldo;
        sscanf(linha.c_str(), "%100[^,], %d,%lf", nome, &idade, &saldo);
        inserirUsuario(nome, idade, saldo);
    }
    cout << "Usuarios inseridos com id " << (proximoId - qtd) << " e " << (proximoId - 1) << "." << endl;
}

int buscarPorId(int id) {
    for (int i = 0; i < totalUsuarios; ++i) {
        if (usuarios[i]->id == id) return i;
    }
    return -1;
}

void buscarUsuario(int id) {
    int idx = buscarPorId(id);
    if (idx != -1) {
        cout << "Usuario " << id << " tem saldo de R$" << fixed << setprecision(2) << usuarios[idx]->saldo << "." << endl;
    } else {
        cout << "Erro: Usuario " << id << " nao encontrado." << endl;
    }
}

void removerUsuario(int id) {
    int idx = buscarPorId(id);
    if (idx != -1) {
        delete usuarios[idx];
        for (int i = idx; i < totalUsuarios - 1; ++i) {
            usuarios[i] = usuarios[i + 1];
        }
        totalUsuarios--;
        cout << "Usuario " << id << " removido com sucesso." << endl;
    } else {
        cout << "Erro: Usuario " << id << " nao encontrado." << endl;
    }
}

void transferir(int origem, int destino, double quantia) {
    int idxOrigem = buscarPorId(origem);
    int idxDestino = buscarPorId(destino);
    if (idxOrigem == -1 || idxDestino == -1) {
        cout << "Erro Usuario de origem ou destino nao encontrado." << endl;
        return;
    }
    if (quantia <= 0 || usuarios[idxOrigem]->saldo < quantia) {
        cout << "Erro: transferencia invalida." << endl;
        return;
    }
    usuarios[idxOrigem]->saldo -= quantia;
    usuarios[idxDestino]->saldo += quantia;
    cout << "Transferencia de R$" << fixed << setprecision(2) << quantia << " realizada com sucesso." << endl;
}

void carregarArquivo(const char* nomeArquivo) {
    ifstream arq(nomeArquivo);
    if (!arq) {
        cout << "Erro: arquivo nao encontrado." << endl;
        return;
    }
    int qtd;
    arq >> qtd;
    arq.ignore();
    for (int i = 0; i < qtd; ++i) {
        string linha;
        getline(arq, linha);
        char nome[101]; int idade; double saldo;
        sscanf(linha.c_str(), "%100[^,], %d,%lf", nome, &idade, &saldo);
        inserirUsuario(nome, idade, saldo);
    }
    arq.close();
}

int main() {
    usuarios = new Usuario*[capacidade];
    int comando;
    while (cin >> comando) {
        cin.ignore();
        if (comando == 1) {
            string linha;
            getline(cin, linha);
            char nome[101]; int idade; double saldo;
            sscanf(linha.c_str(), "%100[^,], %d,%lf", nome, &idade, &saldo);
            inserirUsuario(nome, idade, saldo);
        } else if (comando == 2) {
            int qtd;
            cin >> qtd;
            cin.ignore();
            inserirMultiplos(qtd);
        } else if (comando == 3) {
            int id;
            cin >> id;
            buscarUsuario(id);
        } else if (comando == 4) {
            int origem, destino;
            double quantia;
            cin >> origem >> destino >> quantia;
            transferir(origem, destino, quantia);
        } else if (comando == 5) {
            int id;
            cin >> id;
            removerUsuario(id);
        } else if (comando == 6) {
            string nomeArquivo;
            getline(cin, nomeArquivo);
            carregarArquivo(nomeArquivo.c_str());
        } else {
            break;
        }
    }
    salvarEmArquivo("usuarios.txt");
    for (int i = 0; i < totalUsuarios; ++i) delete usuarios[i];
    delete[] usuarios;
    return 0;
}
