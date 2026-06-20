/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cch.model;

import cch.util.HibernateUtil;
import cch.model.Cidade;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author User
 */
public class CidadeDAO {
    
    public boolean Cadastrar (Cidade cidade) {
        
        Transaction transaction = null;
        HibernateUtil hibernate = new HibernateUtil();
        
        try {
            
            Session session = hibernate.getSessionFactory().openSession();
            
            transaction = session.beginTransaction();
            
            session.persist(cidade);
            
            transaction.commit();
            
            return true;
            
        } catch (Exception e) {
            
            if (transaction != null) {
                transaction.rollback();
            }
            
            return false;

        }
        
        
        
    };
    
    
}
