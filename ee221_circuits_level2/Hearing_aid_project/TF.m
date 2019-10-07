f = logspace (log10 (200), log10 (18000), 35);
g = [10.5 8.75 10.75 11.75 13.75 14 16 16.25 15.25 20 21.5 22.25 21.25 20 19.25 25 25.25 27 25 28 26 24.5 26.5 25 24 26.5 27.75 27.25 28 27.5 24 26 29.5 19.5 4.5];

% dB step size is 2
g = g * 2;

% find transfer function
tf = g - thrhearvals(f);

% normalize transfer function so that gain at most sensitive
% frequency is 0
tf = max(tf) - tf;

% print result as [ frequency | dB ]
[f ; tf]'