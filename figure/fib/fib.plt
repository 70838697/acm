#!/gnuplot
#
#    
#    	G N U P L O T
#    	Version 4.6 patchlevel 0    last modified 2012-03-04 
#    	Build System: MS-Windows 32 bit 
#    
#    	Copyright (C) 1986-1993, 1998, 2004, 2007-2012
#    	Thomas Williams, Colin Kelley and many others
#    
#    	gnuplot home:     http://www.gnuplot.info
#    	faq, bugs, etc:   type "help FAQ"
#    	immediate help:   type "help"  (plot window: hit 'h')
# set terminal wxt 0
# set output
set terminal postscript eps enhanced color font 'Helvetica,10'
set output 'fib.eps'
set xlabel 'n'
set xtics out #是坐标的刻度朝外
set ytics out
Power(x,y)=x**y
Sqrt(x)=Power(x,0.5)
GNUTERM = "wxt"
GPFUN_Power = "Power(x,y)=x**y"
GPFUN_Sqrt = "Sqrt(x)=Power(x,0.5)"
plot 'Z:\doing\acm\acm\figure\fib\fib.txt' title 'Fib(n)' , (((1+Sqrt(5))*0.5)**x)/Sqrt(5) title '(((1+\qrt(5))*0.5)^x)/\sqrt(5)'
set output
#    EOF
