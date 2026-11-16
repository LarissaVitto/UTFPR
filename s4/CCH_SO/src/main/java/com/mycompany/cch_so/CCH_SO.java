package com.mycompany.cch_so;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Larissa Vitto
 */
public class CCH_SO {

    public static void main(String[] args) {
        //Menu para a escolha do tipo de escalonamento
        Scanner scanner = new Scanner(System.in);
        int opcao = 0;
            while (true) {
            System.out.println("=== Simulador de Escalonamento de Processos com Threads ===");
            System.out.println("1 - Escalonamento FIFO");
            System.out.println("2 - Escalonamento por Prioridade");
            System.out.print("Escolha uma opcao: ");
            opcao = scanner.nextInt();
       
            if (opcao == 1 || opcao == 2) {
                break;
            } else {
                System.out.println("\nEssa opcao eh invalida, escolha entre 1 ou 2.\n");
            }
        }
        
        int numeroNucleos = 2; // Escolhi 2 nucleos para a CPU
        
        EscalonadorFIFO escalonadorFIFO = null;
        EscalonadorPrioridade escalonadorPrioridade = null;

        // Inicia o escalonador q foi escolhido
        if (opcao == 1) {
            GerenciadorDeFilas.usarPrioridade = false; // Desativa exibição da prioridade no FIFO
            escalonadorFIFO = new EscalonadorFIFO(numeroNucleos);
            escalonadorFIFO.iniciar();
        } else if (opcao == 2) {
            GerenciadorDeFilas.usarPrioridade = true;  // Ativa exibição na Prioridade
            escalonadorPrioridade = new EscalonadorPrioridade(numeroNucleos);
            escalonadorPrioridade.iniciar();
        }
    
        // Cria os processos com os parametros id, tempoChegada, tempoExecucaoRestante e prioridade
        List<Processo> processosCriados = new ArrayList<>();
        processosCriados.add(new Processo(1, 0, 5, 5));
        processosCriados.add(new Processo(2, 0, 3, 1));
        processosCriados.add(new Processo(3, 3, 4, 3));
        processosCriados.add(new Processo(4, 5, 2, 1));
        
        System.out.println("   PROCESSOS CRIADOS");
        for (Processo p : processosCriados) {
            String infoPrioridade = (opcao == 2) 
                    ? " | Prioridade: " + p.getPrioridade() 
                    : " | Prioridade: N/A (FIFO)";
                    
            System.out.println("Processo " + p.getId() 
                    + " | Chegada: " + p.getTempoChegada() + "s"
                    + " | Duracao: " + p.getTempoExecucaoRestante() + "s"
                    + infoPrioridade
                    + " | Estado: " + p.getEstado());
        }

        System.out.println("\nIniciando relogio do simulador...\n");
        int relogioGlobal = 0;
        int processosAdicionados = 0;
        int totalProcessos = processosCriados.size();

        try {
            // Contador de clocks do relogio
            while (processosAdicionados < totalProcessos) {
                
                for (Processo p : processosCriados) {
                    if (p.getTempoChegada() == relogioGlobal) {
                        System.out.println("[Tempo " + relogioGlobal + "] Processo " + p.getId() + " iniciou.");
                        
                        // Diz qual fila vai o processo pelo escalonador
                        if (opcao == 1) {
                            GerenciadorDeFilas.filaProntos.adicionar(p);
                        } else {
                            escalonadorPrioridade.filaDePrioridade.put(p);
                        }
                        processosAdicionados++;
                    }
                }
                
                relogioGlobal++;
                Thread.sleep(1000); 
            }
            
            // Espera o processamento da CPU
            Thread.sleep(8000); 
            
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Desliga o escalonador que havia sido escolhido
        if (opcao == 1) escalonadorFIFO.desligar();
        else escalonadorPrioridade.desligar();
        
        System.out.println("===   ORDEM DE ENTRADA NO PROCESSADOR    ===");
        for (String registro : GerenciadorDeFilas.ordemEntradaCPU) {
            System.out.println(registro);
        }

        System.out.println("===  PROCESSOS FINALIZADOS    ===");
        for (Processo p : GerenciadorDeFilas.finalizados.getLista()) {
            String infoPrioridade = GerenciadorDeFilas.usarPrioridade 
                    ? " | Prioridade: " + p.getPrioridade() 
                    : " | Prioridade: nao utilizada";
                    
            System.out.println("Processo " + p.getId() + " | Estado: " + p.getEstado() + infoPrioridade);
        }
        
        scanner.close();
        System.exit(0);
    }
}