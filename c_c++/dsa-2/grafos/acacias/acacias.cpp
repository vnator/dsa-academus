#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Aresta {
    int origem, destino;
    long long peso;
    
    Aresta(int o, int d, long long p) : origem(o), destino(d), peso(p) {}
    
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

class UnionFind {
private:
    vector<int> pai, rank;
    
public:
    UnionFind(int n) {
        pai.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            pai[i] = i;
        }
    }
    
    int find(int x) {
        if (pai[x] != x) {
            pai[x] = find(pai[x]);
        }
        return pai[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false;
        }
        
        if (rank[rootX] < rank[rootY]) {
            pai[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            pai[rootY] = rootX;
        } else {
            pai[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
    
    // Conta quantos componentes distintos existem (apenas vértices válidos 1-n)
    int contarComponentes(int n) {
        vector<bool> visitado(n + 1, false);
        int componentes = 0;
        
        for (int i = 1; i <= n; i++) { // Só conta vértices de 1 a n
            int root = find(i);
            if (!visitado[root]) {
                visitado[root] = true;
                componentes++;
            }
        }
        
        return componentes;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Aresta> arestas;
    
    // Lê as pontes para cada habitação de 1 a N-1
    for (int i = 1; i <= n - 1; i++) {
        int k;
        cin >> k;
        
        // Lê k pares (destino, custo)
        for (int p = 0; p < k; p++) {
            int j;
            long long custo;
            cin >> j >> custo;
            
            // Adiciona a aresta (ponte) de i para j
            arestas.emplace_back(i, j, custo);
        }
        
        // Se k = 0, pode ter um 0 explícito na entrada
        if (k == 0) {
            int dummy;
            if (cin.peek() != '\n' && cin >> dummy) {
                // Consome o 0 se estiver lá
            }
        }
    }
    
    // Primeiro: conta quantas famílias (componentes conexos) existem
    UnionFind familias(n + 1);
    for (const auto& aresta : arestas) {
        familias.unite(aresta.origem, aresta.destino);
    }
    
    int numeroFamilias = familias.contarComponentes(n);
    
    // Segundo: encontra custo mínimo para reconectar (MST)
    sort(arestas.begin(), arestas.end());
    
    UnionFind mst(n + 1);
    long long custoTotal = 0;
    
    for (const auto& aresta : arestas) {
        if (mst.unite(aresta.origem, aresta.destino)) {
            custoTotal += aresta.peso;
        }
    }
    
    cout << numeroFamilias << " " << custoTotal << endl;
    
    return 0;
}
