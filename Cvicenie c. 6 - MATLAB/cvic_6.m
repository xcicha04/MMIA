data = csvread('ntc.csv');
t = data(:, 1);
r = data(:, 2);

ad = 1024 * r ./ (r + 10);

p = polyfit(ad, t, 10);
ad2 = 0:1023;
t2 = round(polyval(p, ad2), 1);

plot(ad, t, 'o', ad2, t2, 'r')
xlim([0 1024])
xlabel('ADC value')
ylabel('Temperature °C')
legend('Data from ntc.csv', 'Interpolated data')

t2 = round(t2 * 10);

dlmwrite('data.dlm', t2, ',');
