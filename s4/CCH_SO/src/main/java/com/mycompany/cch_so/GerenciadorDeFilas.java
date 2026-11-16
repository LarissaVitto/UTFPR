/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cch_so;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
/**
 *
 * @author Larissa Vitto
 */
public class GerenciadorDeFilas {
    public static FilaProntos filaProntos = new FilaProntos();
   public static FilaEspera filaEspera = new FilaEspera();
   public static ListaFinalizados finalizados = new ListaFinalizados();

   public GerenciadorDeFilas() {
   }

   //cria a fila de prontos com mutex e a condicao de naoVazia
   public static class FilaProntos {
      private LinkedList<Processo> fila = new LinkedList();
      // Cria o mutex para apenas uma thread mexer na fila por vez
      private Lock mutex = new ReentrantLock();
      //Faz a thread dormir e acordar
      private Condition naoVazia;

      public FilaProntos() {
         this.naoVazia = this.mutex.newCondition();
      }

      public void adicionar(Processo var1) {
         this.mutex.lock(); // Início da exclusão mutua

         try {
            this.fila.add(var1);
            this.naoVazia.signal(); //Acorda o dispach avisando que a fila não está mais vazia

         } finally {
            this.mutex.unlock(); // Fim da exclusao mutua
         }

      }

      public Processo remover() throws InterruptedException {
         this.mutex.lock();

         Processo var1;
         // Se a fila estiver vazia, o dispach dorme para não gastar CPU
         try {
            while(this.fila.isEmpty()) {
               this.naoVazia.await();
            }

            var1 = (Processo)this.fila.poll(); //remove e retorna o primeiro da fila
         } finally {
            this.mutex.unlock();
         }

         return var1;
      }
   }

   public static class FilaEspera {
      private LinkedList<Processo> fila = new LinkedList();
      // Semaforo inicializado com 1, permissão disponível.
      private Semaphore semaforo = new Semaphore(1);

      public FilaEspera() {
      }

      public void adicionar(Processo var1) throws InterruptedException {
         this.semaforo.acquire(); // Tira a permissão com 0

         try {
            this.fila.add(var1);
         } finally {
            this.semaforo.release(); // Da a permissão com 1
         }

      }

      public Processo remover() throws InterruptedException {
         this.semaforo.acquire();

         Processo var1;
         try {
            var1 = (Processo)this.fila.poll();
         } finally {
            this.semaforo.release();
         }

         return var1;
      }
   }

   public static class ListaFinalizados {
      private List<Processo> lista = new ArrayList();
      // Usa o mutex para proteger o histórico de processos terminados trancando eles
      private Lock mutex = new ReentrantLock();

      public ListaFinalizados() {
      }

      public void adicionar(Processo var1) {
         this.mutex.lock();

         try {
            this.lista.add(var1);
         } finally {
            this.mutex.unlock();
         }

      }

      public List<Processo> getLista() {
         this.mutex.lock();

         ArrayList var1;
         try {
            var1 = new ArrayList(this.lista);
         } finally {
            this.mutex.unlock();
         }

         return var1;
      }
   }
   
   // Lista com Mutex para registrar a ordem de entrada na CPU
    public static List<String> ordemEntradaCPU = new ArrayList<>();
    private static Lock mutexOrdem = new ReentrantLock();
    public static boolean usarPrioridade = false;

    public static void registrarEntradaCPU(Processo p, String nomeNucleo) {
        mutexOrdem.lock();
        try {
            int posicao = ordemEntradaCPU.size() + 1;
            
            // Define o texto dependendo do escalonador
            String infoPrioridade = usarPrioridade 
                    ? "Prioridade: " + p.getPrioridade() 
                    : "Prioridade: N/A (FIFO)";
            
            String registro = posicao + " -> Processo " + p.getId() + " (" + infoPrioridade + ") entrou no " + nomeNucleo;
            ordemEntradaCPU.add(registro);
            System.out.println(">>> [CPU] " + registro);
        } finally {
            mutexOrdem.unlock();
        }
    }
}
