/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cch.util;

import org.h2.tools.Server;

/**
 *
 * @author evand
 */
public class H2Console {
    
    public static void main(String[] args) throws Exception {

        Server.createWebServer(
                "-web",
                "-webAllowOthers",
                "-webPort",
                "8082")
              .start();

        System.out.println(
                "Console H2 iniciado em http://localhost:8082");
    }
    
}
