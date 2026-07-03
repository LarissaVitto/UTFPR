/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cch.model;

import cch.util.HibernateUtil;
import cch.model.Cliente;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;
/**
 *
 * @author Notebook
 */
public class ClienteDAO {
    public boolean Cadastrar (Cliente cliente) {
        Transaction transaction = null;
        HibernateUtil hibernate = new HibernateUtil();
        
          try  {
            Session session = hibernate.getSessionFactory().openSession();
            
            transaction = session.beginTransaction();
            
            session.persist(cliente);
            
            transaction.commit();
            
            return true;
          } catch (Exception e){
              if(transaction != null){
                  transaction.rollback();
              }
              return false;
          }
    }
    
    public List<Cliente> buscarTodos () {
         HibernateUtil hibernate = new HibernateUtil();
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            String hql = "FROM Cliente";
            Query<Cliente> query = session.createQuery(hql, Cliente.class);
            
            return query.list();
        } catch (Exception e) {
            return new ArrayList<>(); 
        }
    
    }
    
    public List<Cliente> buscarPorNome(String nome) {
        HibernateUtil hibernate = new HibernateUtil();
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            String hql = "FROM Cliente WHERE nome LIKE :nome";
            Query<Cliente> query = session.createQuery(hql, Cliente.class);
            query.setParameter("nome", "%" + nome + "%");
            
            return query.list();
        } catch (Exception e) {
            return new ArrayList<>(); 
        }
    }
    public boolean Alterar (Cliente cliente){
        Transaction transaction = null;
        HibernateUtil hibernate = new HibernateUtil();
        
        try {
            Session session = hibernate.getSessionFactory().openSession();
            
            transaction = session.beginTransaction();
            
            session.merge(cliente);
            
            transaction.commit();
            
            return true;
            
        }catch (Exception e){
            if (transaction != null){
                transaction.rollback();
            }
            return false;
        }
    }
    
    public boolean Excluir (Cliente cliente){
        Transaction transaction = null;
        HibernateUtil hibernate = new HibernateUtil();
        
        try {
            Session session = hibernate.getSessionFactory().openSession();
            
            transaction = session.beginTransaction();
            
            session.remove(cliente);
            
            transaction.commit();
            
            return true;
            
        }catch (Exception e){
            if (transaction != null){
                transaction.rollback();
            }
            return false;
        }
    }
}
