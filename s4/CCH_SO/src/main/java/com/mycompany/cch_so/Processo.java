/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cch_so;

/**
 *
 * @author Larissa Vitto
 */

// O runnable transforma a classe em uma tarefa rodavel permitindo q a thread execute
public class Processo implements Runnable {
   private int id;
   private int tempoChegada;
   private int tempoExecucaoRestante;
   private int prioridade;
   private EstadoProcesso estado;

   public Processo(int var1, int var2, int var3, int var4) {
      this.id = var1;
      this.tempoChegada = var2;
      this.tempoExecucaoRestante = var3;
      this.prioridade = var4;
      this.estado = EstadoProcesso.READY; //qnd cria o processo fica pronto pra ir pra CPU

   }

   public int getId() {
      return this.id;
   }

   public int getTempoChegada() {
      return this.tempoChegada;
   }

   public EstadoProcesso getEstado() {
      return this.estado;
   }

   public void setEstado(EstadoProcesso var1) {
      this.estado = var1;
   }

   public int getTempoExecucaoRestante() {
      return this.tempoExecucaoRestante;
   }

   public int getPrioridade() {
      return this.prioridade;
   }

   //Roda o processo qnd o despatch envia
   public void run() {
       // Muda o status para Executando qnd entra na CPU
      this.estado = EstadoProcesso.RUNNING;
      int var10001 = this.id;
      System.out.println("Processo " + var10001 + " executando em: " + Thread.currentThread().getName());

      try {
         // Looping para continuar rodando enquanto ainda tiver tempo sobrando e n estar pausado
         while(this.tempoExecucaoRestante > 0 && this.estado == EstadoProcesso.RUNNING) {
             // Espera 1 segunfo para simular o tempo que o processador leva para processar as instruções
            Thread.sleep(1000L);
            // A cada clock, reduz 1 do tempo restante
            --this.tempoExecucaoRestante;
            System.out.println("Processo " + this.id + " - Tempo restante: " + this.tempoExecucaoRestante);
         }
         // Se o tempo zerou, o processo esta finalizado
         if (this.tempoExecucaoRestante == 0) {
            this.estado = EstadoProcesso.FINISHED;
            System.out.println("Processo " + this.id + " finalizou.");
         }
      } catch (InterruptedException var2) {
         System.out.println("Processo " + this.id + " foi interrompido/preemptado.");
      }

   }
}

