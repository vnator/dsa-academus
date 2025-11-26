#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int INF = INT_MAX;

struct Aresta {
    int destino, capacidade, custo, fluxo, rev;
    Aresta(int d, int cap, int c, int rev_idx) : 
           destino(d), capacidade(cap), custo(c), fluxo(0), rev(rev_idx) {}
};

vector<Aresta> grafo[MAXN];
int dist[MAXN], pai_no[MAXN], pai_aresta[MAXN];
bool em_fila[MAXN];

void adicionarAresta(int u, int v, int cap, int custo) {
    grafo[u].push_back(Aresta(v, cap, custo, grafo[v].size()));
    grafo[v].push_back(Aresta(u, 0, -custo, grafo[u].size() - 1));
}

bool spfa(int origem, int destino, int n) {
    fill(dist, dist + n + 1, INF);
    memset(em_fila, false, sizeof(em_fila));
    
    dist[origem] = 0;
    queue<int> fila;
    fila.push(origem);
    em_fila[origem] = true;
    
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        em_fila[u] = false;
        
        for (size_t i = 0; i < grafo[u].size(); i++) {
            Aresta& aresta = grafo[u][i];
            int v = aresta.destino;
            int capacidade_residual = aresta.capacidade - aresta.fluxo;
            
            if (capacidade_residual > 0 && dist[v] > dist[u] + aresta.custo) {
                dist[v] = dist[u] + aresta.custo;
                pai_no[v] = u;
                pai_aresta[v] = i;
                
                if (!em_fila[v]) {
                    fila.push(v);
                    em_fila[v] = true;
                }
            }
        }
    }
    
    return dist[destino] != INF;
}

long long minCostMaxFlow(int origem, int destino, int n, int demanda) {
    long long custo_total = 0;
    int fluxo_atual = 0;
    
    while (fluxo_atual < demanda) {
        if (!spfa(origem, destino, n)) {
            return -1; // Impossível
        }
        
        // Encontrar gargalo do caminho
        int fluxo_caminho = demanda - fluxo_atual;
        int atual = destino;
        
        while (atual != origem) {
            int anterior = pai_no[atual];
            int idx = pai_aresta[atual];
            int cap_residual = grafo[anterior][idx].capacidade - grafo[anterior][idx].fluxo;
            fluxo_caminho = min(fluxo_caminho, cap_residual);
            atual = anterior;
        }
        
        // Atualizar fluxos
        atual = destino;
        while (atual != origem) {
            int anterior = pai_no[atual];
            int idx = pai_aresta[atual];
            
            grafo[anterior][idx].fluxo += fluxo_caminho;
            grafo[atual][grafo[anterior][idx].rev].fluxo -= fluxo_caminho;
            
            custo_total += (long long)fluxo_caminho * grafo[anterior][idx].custo;
            atual = anterior;
        }
        
        fluxo_atual += fluxo_caminho;
    }
    
    return custo_total;
}

int main() {
    int n, m, instancia = 1;
    
    while (cin >> n >> m && (n || m)) {
        // Limpar grafo
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
        }
        
        // Ler rotas
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            // Como será definido depois, usar capacidade temporária de 1
            adicionarAresta(a, b, 1, c);
            adicionarAresta(b, a, 1, c);
        }
        
        int d, k;
        cin >> d >> k;
        
        // Atualizar capacidades com o valor correto K
        for (int i = 1; i <= n; i++) {
            for (auto& aresta : grafo[i]) {
                if (aresta.capacidade == 1) {
                    aresta.capacidade = k;
                }
            }
        }
        
        cout << "Instancia " << instancia << endl;
        
        long long resultado = minCostMaxFlow(1, n, n, d);
        
        if (resultado == -1) {
            cout << "impossivel" << endl;
        } else {
            cout << resultado << endl;
        }
        cout << endl;
        
        instancia++;
    }
    
    return 0;
}