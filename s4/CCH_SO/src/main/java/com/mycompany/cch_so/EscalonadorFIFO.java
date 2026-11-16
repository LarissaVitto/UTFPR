/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cch_so;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

/**
 *
 * @author Larissa Vitto
 */
public class EscalonadorFIFO {
    private int numeroDeNucleos;
   private ExecutorService cpuCores;

   public EscalonadorFIFO(int var1) {
      this.numeroDeNucleos = var1;
      // Cria um grupo fixo de threads com o newFixedThreadPool e 
      // se var1 for 2 como o escolhido, apenas 2 threads podem rodar processos simultaneamente
      // e O resto fica travado esperando um núcleo liberar.
      this.cpuCores = Executors.newFixedThreadPool(var1);
   }

   public void iniciar() {
        System.out.println("Iniciando Escalonador com " + numeroDeNucleos + " nucleos.");

        // Criada a variavel dispatcher para guardar a thread, pois é o dispatcher que envia o processo que o escalonador escolheu pra CPU
        Thread dispatcher = new Thread(() -> {
            while (true) {
                try {
                    Processo p = GerenciadorDeFilas.filaProntos.remover();

                    cpuCores.submit(() -> {
                        GerenciadorDeFilas.registrarEntradaCPU(p, Thread.currentThread().getName());
                        p.run(); 
                        GerenciadorDeFilas.finalizados.adicionar(p); 
                    });

                } catch (InterruptedException e) {
                    System.out.println("O dispatcher do escalonador sofreu uma interrupcao.");
                    break;
                }
            }
        });
        
        dispatcher.setDaemon(true); //Daemon serve para ele finalizar qnd acaba a tarefa principal
        dispatcher.start(); 
    }

   public void desligar() {
      this.cpuCores.shutdown();

      try {
         this.cpuCores.awaitTermination(15L, TimeUnit.SECONDS);
      } catch (InterruptedException var2) {
         var2.printStackTrace();
      }

   }
}
