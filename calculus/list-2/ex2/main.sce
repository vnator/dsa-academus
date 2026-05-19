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
deff('y = phi_a(x)', 'y = exp(-2.0 * x)');

deff('y = f_b(x)', 'y = log(x) - x + 2.0');
deff('y = phi_b(x)', 'y = log(x) + 2.0');

deff('y = f_c(x)', 'y = exp(x / 2.0) - x^3');
deff('y = phi_c(x)', 'y = exp(x / 6.0)');

deff('y = f_d(x)', 'y = sin(x) - x^2');
deff('y = phi_d(x)', 'y = sqrt(sin(x))');

deff('y = f_e(x)', 'y = x / 4.0 - cos(x)');
deff('y = phi_e(x)', 'y = acos(x / 4.0)');

tol_f = 1e-5;
tol_x = 1e-5;
max_iter = 10000;

disp('========== RESULTADOS - EXERCICIO 2 (MIL) ==========');
disp('Criterios de parada: |f(x)| <= 10^-5 ou Delta x <= 10^-5');
disp(' ');

disp('--- ALINEA (a): x0 = 0.45 ---');
[root_a, iter_a, time_a] = mil(0.45, phi_a, f_a, tol_f, tol_x, max_iter);
printf('MIL: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_a, iter_a, abs(f_a(root_a)), time_a);
disp(' ');

disp('--- ALINEA (b): x0 = 3.50 ---');
[root_b, iter_b, time_b] = mil(3.50, phi_b, f_b, tol_f, tol_x, max_iter);
printf('MIL: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_b, iter_b, abs(f_b(root_b)), time_b);
disp(' ');

disp('--- ALINEA (c): x0 = 1.50 ---');
[root_c, iter_c, time_c] = mil(1.50, phi_c, f_c, tol_f, tol_x, max_iter);
printf('MIL: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_c, iter_c, abs(f_c(root_c)), time_c);
disp(' ');

disp('--- ALINEA (d): x0 = 0.75 ---');
[root_d, iter_d, time_d] = mil(0.75, phi_d, f_d, tol_f, tol_x, max_iter);
printf('MIL: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_d, iter_d, abs(f_d(root_d)), time_d);
disp(' ');

disp('--- ALINEA (e): x0 = 1.25 ---');
[root_e, iter_e, time_e] = mil(1.25, phi_e, f_e, tol_f, tol_x, max_iter);
printf('MIL: Raiz = %.6f | Iteracoes = %d | Erro = %.6f | Tempo = %.6f ms\n', root_e, iter_e, abs(f_e(root_e)), time_e);
disp(' ');