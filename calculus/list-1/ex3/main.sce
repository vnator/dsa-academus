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

deff('y = f(x)', 'y = x^6 - 1249');

a = 3;
b = 4;
epsilon = 1e-12;
sigma = 1e-6;
max_iter = 100000;

disp('===== EXERCICIO 3: BISSECCAO VS FALSA POSICAO =====');
printf('Problema: calcular 1249^(1/6)\n');
printf('Intervalo inicial: [%.1f, %.1f]\n', a, b);
printf('Criterios: |f(xk)| <= %.1e OU |bk-ak| <= %.1e\n\n', epsilon, sigma);

[rb, ib, tb, eb, wb] = bisection(a, b, f, epsilon, sigma, max_iter);
[rf, ifp, tf, ef, wf] = false_position(a, b, f, epsilon, sigma, max_iter);

printf('Bisseccao     -> raiz=%.10f | raiz(5 casas)=%.5f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n', rb, rb, ib, tb, eb, wb);
printf('Falsa Posicao -> raiz=%.10f | raiz(5 casas)=%.5f | it=%d | tempo=%.6f ms | |f(x)|=%.3e | |b-a|=%.3e\n', rf, rf, ifp, tf, ef, wf);
