#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class GrafoComponentesConexos {
private:
    vector<vector<int>> adj; // Lista de adjacência
    vector<bool> visitado;
    int numVertices;
    
    // DFS para encontrar todos os vértices conectados a partir de um vértice
    void dfs(int vertice, vector<int>& componente) {
        visitado[vertice] = true;
        componente.push_back(vertice);
        
        // Visita todos os vértices adjacentes não visitados
        for (int vizinho : adj[vertice]) {
            if (!visitado[vizinho]) {
                dfs(vizinho, componente);
            }
        }
    }
    
public:
    GrafoComponentesConexos(int v) : numVertices(v) {
        adj.resize(v);
        visitado.resize(v);
    }
    
    // Adiciona uma aresta ao grafo (grafo não direcionado)
    void adicionarAresta(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Grafo não direcionado
    }
    
    // Encontra todos os componentes conexos
    vector<vector<int>> encontrarComponentesConexos() {
        vector<vector<int>> componentes;
        
        // Reinicia o array de visitados
        fill(visitado.begin(), visitado.end(), false);
        
        // Para cada vértice não visitado, inicia uma nova busca DFS
        for (int i = 0; i < numVertices; i++) {
            if (!visitado[i]) {
                vector<int> componente;
                dfs(i, componente);
                
                // Ordena os vértices do componente
                sort(componente.begin(), componente.end());
                componentes.push_back(componente);
            }
        }
        
        return componentes;
    }
};

// Converte caractere para índice (a=0, b=1, etc.)
int charParaIndice(char c) {
    return c - 'a';
}

// Converte índice para caractere (0=a, 1=b, etc.)
char indiceParaChar(int i) {
    return 'a' + i;
}

int main() {
    int n; // Número de casos de teste
    cin >> n;
    
    for (int caso = 1; caso <= n; caso++) {
        int v, e; // Número de vértices e arestas
        cin >> v >> e;
        
        GrafoComponentesConexos grafo(v);
        
        // Lê as arestas
        for (int i = 0; i < e; i++) {
            char u, w;
            cin >> u >> w;
            
            int indiceU = charParaIndice(u);
            int indiceW = charParaIndice(w);
            
            grafo.adicionarAresta(indiceU, indiceW);
        }
        
        // Encontra os componentes conexos
        vector<vector<int>> componentes = grafo.encontrarComponentesConexos();
        
        // Ordena os componentes pelo menor vértice de cada componente
        sort(componentes.begin(), componentes.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        
        // Imprime o resultado
        cout << "Case #" << caso << ":" << endl;
        
        for (const auto& componente : componentes) {
            for (int vertice : componente) {
                cout << indiceParaChar(vertice) << ",";
            }
            cout << endl;
        }
        
        cout << componentes.size() << " connected components" << endl;
        cout << endl; // Linha em branco após cada caso
    }
    
    return 0;
}
