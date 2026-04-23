function [root, iterations, time_ms, fx_abs, interval_abs] = bisection(a, b, f, epsilon, sigma, max_iter)
    tic();
    iterations = 0;
    fa = f(a);
    fb = f(b);

    if fa * fb > 0 then
        root = %nan;
        time_ms = toc() * 1000;
        fx_abs = %nan;
        interval_abs = abs(b - a);
        return;
    end

    while iterations < max_iter
        xk = (a + b) / 2;
        fx = f(xk);
        iterations = iterations + 1;

        if fa * fx < 0 then
            b = xk;
            fb = fx;
        else
            a = xk;
            fa = fx;
        end

        if abs(fx) <= epsilon | abs(b - a) <= sigma then
            break;
        end
    end

    root = xk;
    fx_abs = abs(fx);
    interval_abs = abs(b - a);
    time_ms = toc() * 1000;
endfunction

function [root, iterations, time_ms, fx_abs, interval_abs] = false_position(a, b, f, epsilon, sigma, max_iter)
    tic();
    iterations = 0;
    fa = f(a);
    fb = f(b);

    if fa * fb > 0 then
        root = %nan;
        time_ms = toc() * 1000;
        fx_abs = %nan;
        interval_abs = abs(b - a);
        return;
    end

    while iterations < max_iter
        denom = fb - fa;
        if abs(denom) < 1d-15 then
            break;
        end

        xk = (a * fb - b * fa) / denom;
        fx = f(xk);
        iterations = iterations + 1;

        if fa * fx < 0 then
            b = xk;
            fb = fx;
        else
            a = xk;
            fa = fx;
        end

        if abs(fx) <= epsilon | abs(b - a) <= sigma then
            break;
        end
    end

    root = xk;
    fx_abs = abs(fx);
    interval_abs = abs(b - a);
    time_ms = toc() * 1000;
endfunction

deff('y = f_a(x)', 'y = exp(-x) - sin(x)');
deff('y = f_b(x)', 'y = x^3 - x*exp(x) + 3');
deff('y = f_c(x)', 'y = sin(x) - log(x)');

epsilon = 1e-5;
sigma = 1e-5;
max_iter = 100000;

disp('===== EXERCICIO 2: BISSECCAO VS FALSA POSICAO =====');
printf('Criterios: |f(xk)| <= %.1e OU |bk-ak| <= %.1e\n\n', epsilon, sigma);

printf('Funcao (a): f(x)=e^(-x)-sen(x), intervalo [0,1]\n');
[rb, ib, tb, eb, wb] = bisection(0, 1, f_a, epsilon, sigma, max_iter);
[rf, ifp, tf, ef, wf] = false_position(0, 1, f_a, epsilon, sigma, max_iter);
printf('Bisseccao     -> raiz=%.10f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n', rb, ib, tb, eb, wb);
printf('Falsa Posicao -> raiz=%.10f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n\n', rf, ifp, tf, ef, wf);

printf('Funcao (b): f(x)=x^3-xe^x+3, intervalo [1,2]\n');
[rb, ib, tb, eb, wb] = bisection(1, 2, f_b, epsilon, sigma, max_iter);
[rf, ifp, tf, ef, wf] = false_position(1, 2, f_b, epsilon, sigma, max_iter);
printf('Bisseccao     -> raiz=%.10f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n', rb, ib, tb, eb, wb);
printf('Falsa Posicao -> raiz=%.10f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n\n', rf, ifp, tf, ef, wf);

printf('Funcao (c): f(x)=sen(x)-ln(x), intervalo [2,3]\n');
[rb, ib, tb, eb, wb] = bisection(2, 3, f_c, epsilon, sigma, max_iter);
[rf, ifp, tf, ef, wf] = false_position(2, 3, f_c, epsilon, sigma, max_iter);
printf('Bisseccao     -> raiz=%.10f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n', rb, ib, tb, eb, wb);
printf('Falsa Posicao -> raiz=%.10f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n', rf, ifp, tf, ef, wf);
