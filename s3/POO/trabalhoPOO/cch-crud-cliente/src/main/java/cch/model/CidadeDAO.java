/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cch.model;

import cch.util.HibernateUtil;
import cch.model.Cidade;
import java.util.ArrayList;
import org.hibernate.Session;
import org.hibernate.Transaction;
import java.util.List;
import org.hibernate.query.Query;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;
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
    
    public List<Cidade> buscarPorNome(String nome) {
        HibernateUtil hibernate = new HibernateUtil();
        try (Session session = HibernateUtil.getSessionFactory().openSession()) {
            String hql = "FROM Cidade WHERE nome LIKE :nome";
            Query<Cidade> query = session.createQuery(hql, Cidade.class);
            query.setParameter("nome", "%" + nome + "%");
            
            return query.list();
        } catch (Exception e) {
            e.printStackTrace();
            return new ArrayList<>(); // Retorna lista vazia em caso de erro
        }
    }
    
    public boolean Alterar (Cidade cidade){
        Transaction transaction = null;
        HibernateUtil hibernate = new HibernateUtil();
        try {
            Session session = hibernate.getSessionFactory().openSession();
            
            transaction = session.beginTransaction();
            
            session.merge(cidade);
            
            transaction.commit();
            
            return true;
            
        }catch (Exception e){
            if (transaction != null){
                transaction.rollback();
            }
            return false;
        }
    }
    
    public boolean Excluir (Cidade cidade){
        Transaction transaction = null;
        HibernateUtil hibernate = new HibernateUtil();
        
        try{
            Session session = hibernate.getSessionFactory().openSession();
            
            transaction = session.beginTransaction();
            
            session.remove(cidade);
            
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
