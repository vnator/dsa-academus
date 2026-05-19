function [root, iterations, time_ms] = newton_raphson(x0, f, df, tol_f, tol_x, max_iter)
    tic();
    iterations = 0;
    xk = x0;

    while iterations < max_iter
        fx = f(xk);
        
        if tol_f > 0.0 & abs(fx) <= tol_f then
            break;
        end
        
        dfx = df(xk);
        if abs(dfx) < 1e-15 then
            break;
        end
        
        x_next = xk - (fx / dfx);
        iterations = iterations + 1;
        
        if tol_x > 0.0 & abs(x_next - xk) <= tol_x then
            xk = x_next;
            break;
        end
        
        xk = x_next;
    end

    root = xk;
    time_ms = toc() * 1000;
endfunction

function [root, iterations, time_ms] = mil(x0, phi, f, tol_f, tol_x, max_iter)
    tic();
    iterations = 0;
    xk = x0;

    while iterations < max_iter
        if tol_f > 0.0 & abs(f(xk)) <= tol_f then
            break;
        end
        
        x_next = phi(xk);
        iterations = iterations + 1;
        
        if tol_x > 0.0 & abs(x_next - xk) <= tol_x then
            xk = x_next;
            break;
        end
        
        xk = x_next;
    end

    root = xk;
    time_ms = toc() * 1000;
endfunction

deff('y = f_a(x)', 'y = x^3 - x + 1.0');
deff('y = df_a(x)', 'y = 3.0 * x^2 - 1.0');
deff('y = phi_a(x)', 'y = sign(x - 1.0) * abs(x - 1.0)^(1/3)');

deff('y = f_b(x)', 'y = x^2 + 3.0 * x - cos(x) - 2.45');
deff('y = df_b(x)', 'y = 2.0 * x + 3.0 + sin(x)');
deff('y = phi_b(x)', 'y = (-x^2 + cos(x) + 2.45) / 3.0');

tol_f = 1e-3;
tol_x = 0.0;
max_iter = 10000;

disp('========== RESULTADOS - EXERCICIO 1 ==========');
disp('Criterio de parada adotado: |f(x)| <= 10^-3');
disp(' ');

disp('--- FUNCAO (a): x0 = -1.5 ---');
[root_nr_a, iter_nr_a, time_nr_a] = newton_raphson(-1.5, f_a, df_a, tol_f, tol_x, max_iter);
[root_mil_a, iter_mil_a, time_mil_a] = mil(-1.5, phi_a, f_a, tol_f, tol_x, max_iter);
printf('Newton-Raphson: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_nr_a, iter_nr_a, abs(f_a(root_nr_a)), time_nr_a);
printf('MIL:            Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_mil_a, iter_mil_a, abs(f_a(root_mil_a)), time_mil_a);
disp(' ');

disp('--- FUNCAO (b): x0 = 0.75 ---');
[root_nr_b, iter_nr_b, time_nr_b] = newton_raphson(0.75, f_b, df_b, tol_f, tol_x, max_iter);
[root_mil_b, iter_mil_b, time_mil_b] = mil(0.75, phi_b, f_b, tol_f, tol_x, max_iter);
printf('Newton-Raphson: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_nr_b, iter_nr_b, abs(f_b(root_nr_b)), time_nr_b);
printf('MIL:            Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_mil_b, iter_mil_b, abs(f_b(root_mil_b)), time_mil_b);
disp(' ');