#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        // Matrizes de conectividade para cada empresa (a-z)
        bool conectado[26][201][201];
        
        // Inicializar todas as matrizes como false
        for (int emp = 0; emp < 26; emp++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    conectado[emp][i][j] = false;
                }
            }
        }
        
        // Ler conexões
        int a, b;
        while (cin >> a >> b && (a != 0 || b != 0)) {
            string empresas;
            cin >> empresas;
            
            // Marcar conexões diretas para cada empresa
            for (char c : empresas) {
                int emp = c - 'a';  // converter 'a'-'z' para 0-25
                conectado[emp][a][b] = true;
            }
        }
        
        // Floyd-Warshall para fechamento transitivo
        // Para cada empresa
        for (int emp = 0; emp < 26; emp++) {
            // Para cada vértice intermediário k
            for (int k = 1; k <= n; k++) {
                // Para cada origem i
                for (int i = 1; i <= n; i++) {
                    // Otimização: só verifica se i alcança k
                    if (conectado[emp][i][k]) {
                        // Para cada destino j
                        for (int j = 1; j <= n; j++) {
                            // Se i alcança k E k alcança j, então i alcança j
                            conectado[emp][i][j] = conectado[emp][i][j] || 
                                                  (conectado[emp][i][k] && conectado[emp][k][j]);
                        }
                    }
                }
            }
        }
        
        // Processar consultas
        while (cin >> a >> b && (a != 0 || b != 0)) {
            string resultado = "";
            
            // Verificar todas as empresas em ordem alfabética
            for (int emp = 0; emp < 26; emp++) {
                if (conectado[emp][a][b]) {
                    resultado += (char)('a' + emp);
                }
            }
            
            if (resultado.empty()) {
                cout << "-" << endl;
            } else {
                cout << resultado << endl;
            }
        }
        
        cout << endl;  // Linha em branco após cada caso de teste
    }
    
    return 0;
}