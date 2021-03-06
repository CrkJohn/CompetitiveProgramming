/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.eci.arsw.primefinder;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 */
public class Control extends Thread {
    
    private final static int NTHREADS = 3;
    private final static int MAXVALUE = 30000000;
    private final static int TMILISECONDS = 5000;
    private static int primesFound = 0;
    private final int NDATA = MAXVALUE / NTHREADS;
    private static Object sync = new Object();


    private PrimeFinderThread pft[];
    
    private Control() {
        super();
        this.pft = new  PrimeFinderThread[NTHREADS];

        int i;
        for(i = 0;i < NTHREADS - 1; i++) {
            PrimeFinderThread elem = new PrimeFinderThread(i*NDATA, (i+1)*NDATA);
            pft[i] = elem;
        }
        pft[i] = new PrimeFinderThread(i*NDATA, MAXVALUE + 1);
    }
    
    public static Control newControl() {
        return new Control();
    }

    @Override
    public void run() {
        for(int i = 0;i < NTHREADS;i++ ) {
            pft[i].start();
        }
        while(true) {
	        for (PrimeFinderThread primeFinderThread : pft) {
				synchronized (sync) {
					try {
						primeFinderThread.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					primesFound+= (primeFinderThread.getPrimes().size());
				}	
				System.out.println("Total primes " + primesFound);
				sync.notifyAll();
				try {
					Thread.sleep(TMILISECONDS);
					BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			        System.out.print("Enter");
			        br.readLine();
				}catch (InterruptedException e) {
					e.printStackTrace();
				}catch (IOException e) {
					e.printStackTrace();
				}
				
	        }
	        System.out.println("Total de los primos son : " + primesFound);
	        
        }
    }
    
}
