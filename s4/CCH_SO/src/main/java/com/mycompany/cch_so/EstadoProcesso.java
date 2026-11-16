/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cch_so;

/**
 *
 * @author Larissa Vitto
 */
public enum EstadoProcesso { // O Enum deixa o processo ter apenas um estado por vez e os valores são constantes
   READY,
   RUNNING,
   WAITING,
   FINISHED;

   private EstadoProcesso() {
   }
}
