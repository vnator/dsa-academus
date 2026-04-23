function [root, iterations, time_ms] = bisection(a, b, f, epsilon, max_iter)
    tic();
    iterations = 0;

    xk = a;
    f_xk = f(xk);
    while abs(f_xk) > epsilon & iterations < max_iter
        iterations = iterations + 1;
        xk = (a + b) / 2.0;
        f_xk = f(xk);
        f_a = f(a);

        if f_a * f_xk < 0 then
            b = xk;
        else
            a = xk;
        end
    end

    root = xk;
    time_ms = toc() * 1000;
endfunction

function [root, iterations, time_ms] = false_position(a, b, f, epsilon, max_iter)
    tic();
    iterations = 0;

    xk = a;
    f_xk = f(xk);
    while abs(f_xk) > epsilon & iterations < max_iter
        iterations = iterations + 1;
        fa = f(a);
        fb = f(b);

        xk = (a * fb - b * fa) / (fb - fa);
        f_xk = f(xk);

        if fa * f_xk < 0 then
            b = xk;
        else
            a = xk;
        end
    end

    root = xk;
    time_ms = toc() * 1000;
endfunction

deff('y = f_a(x)', 'y = x^2 + log(x)');
deff('y = f_b(x)', 'y = exp(x) - x - 2.0');
deff('y = f_c(x)', 'y = x^3 + x - 100.0');

epsilon = 1e-3;
max_iter = 10000;

disp('========== COMPARATIVO: BISSECCAO vs FALSA POSICAO ==========');
disp(' ');

disp('--- FUNCAO A: [0.5, 1.0] ---');
[root_b, iter_b, time_b] = bisection(0.5, 1.0, f_a, epsilon, max_iter);
[root_fp, iter_fp, time_fp] = false_position(0.5, 1.0, f_a, epsilon, max_iter);
printf('Bisseccao:     Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_b, iter_b, abs(f_a(root_b)), time_b);
printf('Falsa Posicao: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_fp, iter_fp, abs(f_a(root_fp)), time_fp);
disp(' ');

disp('--- FUNCAO B: [1.0, 2.0] ---');
[root_b, iter_b, time_b] = bisection(1.0, 2.0, f_b, epsilon, max_iter);
[root_fp, iter_fp, time_fp] = false_position(1.0, 2.0, f_b, epsilon, max_iter);
printf('Bisseccao:     Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_b, iter_b, abs(f_b(root_b)), time_b);
printf('Falsa Posicao: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_fp, iter_fp, abs(f_b(root_fp)), time_fp);
disp(' ');

disp('--- FUNCAO C: [4.0, 5.0] ---');
[root_b, iter_b, time_b] = bisection(4.0, 5.0, f_c, epsilon, max_iter);
[root_fp, iter_fp, time_fp] = false_position(4.0, 5.0, f_c, epsilon, max_iter);
printf('Bisseccao:     Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_b, iter_b, abs(f_c(root_b)), time_b);
printf('Falsa Posicao: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_fp, iter_fp, abs(f_c(root_fp)), time_fp);
