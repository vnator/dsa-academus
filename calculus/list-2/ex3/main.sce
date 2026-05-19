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

deff('y = f_a(x)', 'y = sqrt(x) - exp(-x)');
deff('y = df_a(x)', 'y = 1.0 / (2.0 * sqrt(x)) + exp(-x)');
deff('y = phi_a(x)', 'y = exp(-2.0 * x)');

deff('y = f_b(x)', 'y = log(x) - x + 2.0');
deff('y = df_b(x)', 'y = 1.0 / x - 1.0');
deff('y = phi_b(x)', 'y = log(x) + 2.0');

deff('y = f_c(x)', 'y = exp(x / 2.0) - x^3');
deff('y = df_c(x)', 'y = 0.5 * exp(x / 2.0) - 3.0 * x^2');
deff('y = phi_c(x)', 'y = exp(x / 6.0)');

deff('y = f_d(x)', 'y = sin(x) - x^2');
deff('y = df_d(x)', 'y = cos(x) - 2.0 * x');
deff('y = phi_d(x)', 'y = sqrt(sin(x))');

deff('y = f_e(x)', 'y = x / 4.0 - cos(x)');
deff('y = df_e(x)', 'y = 0.25 + sin(x)');
deff('y = phi_e(x)', 'y = acos(x / 4.0)');

tol_f = 1e-3;
tol_x = 0.0;
max_iter = 10000;

disp('========== RESULTADOS - EXERCICIO 3 ==========');
disp('Criterio de parada: |f(x)| <= 10^-3');
disp(' ');

disp('--- ALINEA (a): x0 = 0.45 ---');
[root_nr_a, iter_nr_a, time_nr_a] = newton_raphson(0.45, f_a, df_a, tol_f, tol_x, max_iter);
[root_mil_a, iter_mil_a, time_mil_a] = mil(0.45, phi_a, f_a, tol_f, tol_x, max_iter);
printf('Newton-Raphson: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_nr_a, iter_nr_a, abs(f_a(root_nr_a)), time_nr_a);
printf('MIL:            Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_mil_a, iter_mil_a, abs(f_a(root_mil_a)), time_mil_a);
disp(' ');

disp('--- ALINEA (b): x0 = 3.50 ---');
[root_nr_b, iter_nr_b, time_nr_b] = newton_raphson(3.50, f_b, df_b, tol_f, tol_x, max_iter);
[root_mil_b, iter_mil_b, time_mil_b] = mil(3.50, phi_b, f_b, tol_f, tol_x, max_iter);
printf('Newton-Raphson: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_nr_b, iter_nr_b, abs(f_b(root_nr_b)), time_nr_b);
printf('MIL:            Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_mil_b, iter_mil_b, abs(f_b(root_mil_b)), time_mil_b);
disp(' ');

disp('--- ALINEA (c): x0 = 1.50 ---');
[root_nr_c, iter_nr_c, time_nr_c] = newton_raphson(1.50, f_c, df_c, tol_f, tol_x, max_iter);
[root_mil_c, iter_mil_c, time_mil_c] = mil(1.50, phi_c, f_c, tol_f, tol_x, max_iter);
printf('Newton-Raphson: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_nr_c, iter_nr_c, abs(f_c(root_nr_c)), time_nr_c);
printf('MIL:            Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_mil_c, iter_mil_c, abs(f_c(root_mil_c)), time_mil_c);
disp(' ');

disp('--- ALINEA (d): x0 = 0.75 ---');
[root_nr_d, iter_nr_d, time_nr_d] = newton_raphson(0.75, f_d, df_d, tol_f, tol_x, max_iter);
[root_mil_d, iter_mil_d, time_mil_d] = mil(0.75, phi_d, f_d, tol_f, tol_x, max_iter);
printf('Newton-Raphson: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_nr_d, iter_nr_d, abs(f_d(root_nr_d)), time_nr_d);
printf('MIL:            Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_mil_d, iter_mil_d, abs(f_d(root_mil_d)), time_mil_d);
disp(' ');

disp('--- ALINEA (e): x0 = 1.25 ---');
[root_nr_e, iter_nr_e, time_nr_e] = newton_raphson(1.25, f_e, df_e, tol_f, tol_x, max_iter);
[root_mil_e, iter_mil_e, time_mil_e] = mil(1.25, phi_e, f_e, tol_f, tol_x, max_iter);
printf('Newton-Raphson: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_nr_e, iter_nr_e, abs(f_e(root_nr_e)), time_nr_e);
printf('MIL:            Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_mil_e, iter_mil_e, abs(f_e(root_mil_e)), time_mil_e);
disp(' ');