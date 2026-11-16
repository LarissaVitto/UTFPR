/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cch_so;
import java.util.Comparator;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.PriorityBlockingQueue;
import java.util.concurrent.TimeUnit;
/**
 *
 * @author Larissa Vitto
 */
public class EscalonadorPrioridade {
    private int numeroDeNucleos;
   private ExecutorService cpuCores;
   // Cria a fila principal pq é segura para múltiplas threads tendo mutex/semáforo, 
   // o priority é pq ela ordena qnd algum processo entra na fila
   public PriorityBlockingQueue<Processo> filaDePrioridade;

   public EscalonadorPrioridade(int var1) {
      this.numeroDeNucleos = var1;
      this.cpuCores = Executors.newFixedThreadPool(var1);
      // Usa o comparador do java para olhar para o atributo "prioridade" para saber quem eh mais prioritario.
      Comparator var2 = Comparator.comparingInt(Processo::getPrioridade);
      // Inicializa a fila de prioridade usando 11 como padrao do java e o var2 que passa a prioridade do comparador
      this.filaDePrioridade = new PriorityBlockingQueue(11, var2);
   }

   public void iniciar() {
        System.out.println("Iniciando Escalonador com " + numeroDeNucleos + " nucleos.");

        // Criada a variavel dispatcher para guardar a thread, pois é o dispatcher que envia o processo que o escalonador escolheu pra CPU
        Thread dispatcher = new Thread(() -> {
            while (true) {
                try {
                    Processo p = this.filaDePrioridade.take();

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
