# Topicos para estudarmos
Vamos focar em memoization, divide and conquer e outros metodos computacionais para funcoes matemáticas fundamentais.

## Algoritmos Matemáticos
Problemas comuns matemáticos abordados em problemas de programacao, mas focados em matematica elementar, teoria dos numeros e geometria.

### 📊 Grupo 1: Fundamentos Absolutos e Otimização de Arrays

*   **Algoritmo de Kadane**: $\max_{i \le j} \sum_{k=i}^j A[k]$, para um array $A$ de inteiros.
*   **Potência (Exponenciação Rápida)**: $x^n = (x^{n/2})^2$ se $n \equiv 0 \pmod 2$, ou $x \cdot (x^{(n-1)/2})^2$ se $n \equiv 1 \pmod 2$.
*   **Soma da Progressão Aritmética**: $S_n = \frac{n(a_1 + a_n)}{2}$, para $n \in \mathbb{N}^*$.
*   **Soma da Progressão Geométrica**: $S_n = \frac{a_1(q^n - 1)}{q - 1}$, para $q \neq 1$.
*   **Logaritmo**: $\log_b(x) = y \iff b^y = x$, para $b, x \in \mathbb{R}_+^* \land b \neq 1$.
*   **Logaritmo Natural**: $\ln(x) = \log_e(x)$, para $x \in \mathbb{R}_+^* \land e \approx 2.718$.

---

### 🔢 Grupo 2: Teoria dos Números e Aritmética Modular

*   **Aritmética dos Restos**: $(a \cdot b) \pmod m = [(a \pmod m) \cdot (b \pmod m)] \pmod m$.
*   **Máximo Divisor Comum**: $\text{mdc}(a, b) = \max \{ d \in \mathbb{Z} : d \mid a \land d \mid b \}$.
*   **Mínimo Múltiplo Comum**: $\text{mmc}(a, b) = \frac{|a \cdot b|}{\text{mdc}(a, b)}$, para $a, b \neq 0$.
*   **Crivo de Eratóstenes**: $P = \{ p \in \mathbb{N} : 2 \le p \le n \land (\forall d \in \mathbb{N}, d \mid p \implies d = 1 \lor d = p) \}$.
*   **Algoritmo de Euclides Estendido**: $ax + by = \text{mdc}(a, b)$, para $a, b, x, y \in \mathbb{Z}$.
*   **Inverso Multiplicativo Modular**: $a \cdot a^{-1} \equiv 1 \pmod m$, onde $\text{mdc}(a, m) = 1$.
*   **Pequeno Teorema de Fermat**: $a^{p-1} \equiv 1 \pmod p$, para $p$ primo $\land \text{mdc}(a, p) = 1$.
*   **Função Totiente de Euler**: $\phi(n) = |\{ k \in \mathbb{N} : 1 \le k \le n \land \text{mdc}(k, n) = 1 \}|$.
*   **Teorema Chinês dos Restos**: $x \equiv a_i \pmod{m_i}$, onde $\text{mdc}(m_i, m_j) = 1$ para $i \neq j$.
*   **Critério de Divisibilidade por Código**: $n \equiv 0 \pmod d \iff f(\text{dígitos de } n) \equiv 0 \pmod d$.

---

### 🎲 Grupo 3: Combinatória, Contagem e Estruturas Discretas

*   **Princípio Fundamental da Contagem**: $\text{Total} = \prod_{i=1}^k n_i$, para $k$ etapas com $n_i$ opções cada.
*   **Triângulo de Pascal**: $\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}$, para $n, k \in \mathbb{N} \land n \ge k$.
*   **Binômio de Newton**: $(x + y)^n = \sum_{k=0}^n \binom{n}{k} x^{n-k} y^k$, para $n \in \mathbb{N}$.
*   **Fatorial**: $n! = \prod_{i=1}^n i$, para $n \in \mathbb{N} \land 0! = 1$.
*   **Permutação com Repetição**: $P_n^{n_1, n_2, \dots, n_k} = \frac{n!}{n_1! \cdot n_2! \dots n_k!}$, onde $\sum_{i=1}^k n_i = n$.
*   **Princípio da Inclusão-Exclusão**: $|A \cup B| = |A| + |B| - |A \cap B|$.
*   **Princípio de Pigeonhole**: $\exists k : |R_k| \ge \lceil n/m \rceil$, para $n$ pombos distribuídos em $m$ caixas.
*   **Números de Catalan**: $C_n = \frac{1}{n+1} \binom{2n}{n}$, para $n \in \mathbb{N}$.

---

### 🔄 Grupo 4: Sequências Recursivas e Simulação

*   **Fibonacci**: $F_n = F_{n-1} + F_{n-2}$, para $n \ge 2 \land F_0=0, F_1=1$.
*   **Fórmula de Binet**: $F_n = \frac{\phi^n - \psi^n}{\sqrt{5}}$, onde $\phi = \frac{1+\sqrt{5}}{2} \land \psi = \frac{1-\sqrt{5}}{2}$.
*   **Sequência de Collatz**: $f(n) = \frac{n}{2}$ se $n \equiv 0 \pmod 2$, ou $3n+1$ se $n \equiv 1 \pmod 2$.
*   **Torre de Hanói**: $H_n = 2^n - 1$, representando o número mínimo de movimentos para $n$ discos.

---

### 📐 Grupo 5: Geometria Discreta e Contagem Avançada

*   **Fórmula de Pick**: $A = i + \frac{b}{2} - 1$, onde $A$ é a área, $i \in \mathbb{N}$ (pontos internos) e $b \in \mathbb{N}$ (pontos na borda).
*   **Fórmula de Polya**: $|Y^X/G| = \frac{1}{|G|} \sum_{g \in G} m^{c(g)}$, onde $G$ é o grupo de permutações e $c(g)$ é o número de ciclos.

---

### 🔗 Grupo 6: Operações entre Conjuntos e Álgebra Booleana

*   **União**: $A \cup B = \{ x : x \in A \lor x \in B \}$. Equivalente ao operador lógico OR (`|` ou `||`).
*   **Intersecção**: $A \cap B = \{ x : x \in A \land x \in B \}$. Equivalente ao operador lógico AND (`&` ou `&&`).
*   **Diferença**: $A \setminus B = \{ x : x \in A \land x \notin B \}$. Retorna elementos exclusivos de $A$ em relação a $B$.
*   **Complementar**: $A^c = \{ x \in U : x \notin A \}$, dado um universo $U$. Equivalente à negação lógica NOT (`!` ou `~`).