function tohv = thrhearvals(f)
%  This function returns an estimate of the dB level correponding to the 
%  threshold of hearing.
% 
%      tohv = thrhearvals(f)
%
%  where input argument F is a vector of frequencies corresponding to 
%  returned threshold of hearing values in output vector TOHV.
%
%   written by Kevin Donohue (donohue@engr.uky.edu) Sept. 2013


%  Measured points for TOH, used for interpolation to obtain TOH
%   at input frequencies
fax = [20 40 100 250 500 750 1000 2e3 3e3 3.2e3 4e3 6e3 8e3 9e3 1e4 12e3 15e3 20e3];
th = [73 49.5 23 10 6 5 4 3 -4 -4.5 -4 5 15 18 16 11 25 100];  %  TOH values in dB
%
tohv = interp1(fax,th,f,'cubic')
