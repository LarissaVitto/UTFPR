package cch.view;

import cch.model.Cidade;
import cch.model.CidadeDAO;
import cch.model.Cliente;
import cch.model.ClienteDAO;
import java.util.List;
import javax.swing.table.DefaultTableModel;

public class Listar extends javax.swing.JFrame {

    private String tipoOrigemTela;
    private static final java.util.logging.Logger logger = java.util.logging.Logger.getLogger(Listar.class.getName());

    public Listar() {
        initComponents();
    }

    public Listar(String tipoOrigemTela) {
        this.tipoOrigemTela = tipoOrigemTela;
        initComponents();
        
        jTableResultados.setDefaultEditor(Object.class, null); //proibe a edição da tabela
        
        // Pega o modelo da tabela e limpa as 4 linhas em branco 
        DefaultTableModel modelo = (DefaultTableModel) jTableResultados.getModel();
        modelo.setNumRows(0); 
        
        if ("CIDADE".equals(tipoOrigemTela)) {
            jLabelTituloPesquisa.setText("PESQUISAR CIDADES");
            modelo.setColumnIdentifiers(new Object[]{"Código", "Nome", "UF"});
            
        } else if ("CLIENTE".equals(tipoOrigemTela)) {
            jLabelTituloPesquisa.setText("PESQUISAR CLIENTES");
            modelo.setColumnIdentifiers(new Object[]{"Código", "Nome", "CPF", "Telefone"});
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabelTituloPesquisa = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        errorMsg = new javax.swing.JLabel();
        jButtonPesquisar = new javax.swing.JButton();
        jTextFieldTermoPesquisado = new javax.swing.JTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTableResultados = new javax.swing.JTable();
        jButtonExcluir = new javax.swing.JButton();
        jButtonAlterar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabelTituloPesquisa.setFont(new java.awt.Font("Arial", 0, 18)); // NOI18N
        jLabelTituloPesquisa.setText("TELA DE PESQUISA");

        jPanel1.setBackground(new java.awt.Color(204, 204, 204));

        errorMsg.setMinimumSize(new java.awt.Dimension(300, 16));

        jButtonPesquisar.setFont(new java.awt.Font("Arial", 0, 12)); // NOI18N
        jButtonPesquisar.setText("PESQUISAR");
        jButtonPesquisar.addActionListener(this::jButtonPesquisarActionPerformed);

        jTextFieldTermoPesquisado.setFont(new java.awt.Font("Arial", 0, 12)); // NOI18N
        jTextFieldTermoPesquisado.setText("Insira o termo de pesquisa...");
        jTextFieldTermoPesquisado.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextFieldTermoPesquisadoFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                jTextFieldTermoPesquisadoFocusLost(evt);
            }
        });
        jTextFieldTermoPesquisado.addActionListener(this::jTextFieldTermoPesquisaActionPerformed);

        jTableResultados.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));
        jScrollPane1.setViewportView(jTableResultados);

        jButtonExcluir.setText("EXCLUIR");
        jButtonExcluir.addActionListener(this::jButtonExcluirActionPerformed);

        jButtonAlterar.setText("ALTERAR");
        jButtonAlterar.addActionListener(this::jButtonAlterarActionPerformed);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(20, 20, 20)
                        .addComponent(errorMsg, javax.swing.GroupLayout.PREFERRED_SIZE, 360, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(14, 14, 14)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(jTextFieldTermoPesquisado, javax.swing.GroupLayout.PREFERRED_SIZE, 286, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(68, 68, 68)
                                .addComponent(jButtonPesquisar))
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 452, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(12, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(86, 86, 86)
                .addComponent(jButtonAlterar, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jButtonExcluir, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(93, 93, 93))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(11, 11, 11)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonPesquisar)
                    .addComponent(jTextFieldTermoPesquisado, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(2, 2, 2)
                .addComponent(errorMsg, javax.swing.GroupLayout.PREFERRED_SIZE, 11, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 279, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonExcluir)
                    .addComponent(jButtonAlterar))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabelTituloPesquisa)
                .addGap(148, 148, 148))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(15, 15, 15)
                .addComponent(jLabelTituloPesquisa)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonPesquisarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonPesquisarActionPerformed
        String termoPesquisa = jTextFieldTermoPesquisado.getText().trim();
        
        if (termoPesquisa.isEmpty() || termoPesquisa.equals("Insira o termo de pesquisa...")) {
            errorMsg.setText("Por favor, digite um termo para a pesquisa.");
            errorMsg.setForeground(java.awt.Color.RED);
            return;
        }
        
        errorMsg.setText("");
          
        DefaultTableModel modelo = (DefaultTableModel) jTableResultados.getModel();
        modelo.setNumRows(0); 

        if ("CIDADE".equals(this.tipoOrigemTela)) { 
            modelo.setColumnIdentifiers(new Object[]{"Código", "Nome", "UF"});
            CidadeDAO cidadeDao = new CidadeDAO();
            List<Cidade> cidades = cidadeDao.buscarPorNome(termoPesquisa);
            
            
            if (cidades.isEmpty()) { // VERIFICA LISTA VAZIA
                errorMsg.setText("Nenhum resultado encontrado para cidades.");
                errorMsg.setForeground(java.awt.Color.BLUE);
            } else {
                for (Cidade c : cidades) {
                    modelo.addRow(new Object[]{c.getId(), c.getNome(), c.getUF()});
                }
            }   
        } else if ("CLIENTE".equals(this.tipoOrigemTela)) {
            modelo.setColumnIdentifiers(new Object[]{"Código", "Nome", "CPF", "Telefone"});
            ClienteDAO clienteDao = new ClienteDAO();
            List<Cliente> clientes = clienteDao.buscarPorNome(termoPesquisa);
            
            if (clientes.isEmpty()) { // VERIFICA LISTA VAZIA
                errorMsg.setText("Nenhum resultado encontrado para clientes.");
                errorMsg.setForeground(java.awt.Color.BLUE);
            } else {
                for (Cliente cli : clientes) {
                    modelo.addRow(new Object[]{cli.getId(), cli.getNome(), cli.getCpf(), cli.getTelefone()});
                }
            }
        }
    }//GEN-LAST:event_jButtonPesquisarActionPerformed

    private void jTextFieldTermoPesquisaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldTermoPesquisaActionPerformed
        jButtonPesquisar.doClick();
    }//GEN-LAST:event_jTextFieldTermoPesquisaActionPerformed

    private void jTextFieldTermoPesquisadoFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextFieldTermoPesquisadoFocusGained
        if (jTextFieldTermoPesquisado.getText().equals("Insira o termo de pesquisa...")) {
        jTextFieldTermoPesquisado.setText(""); // Limpa o texto qnd clica
        jTextFieldTermoPesquisado.setForeground(java.awt.Color.BLACK); 
        }
    }//GEN-LAST:event_jTextFieldTermoPesquisadoFocusGained

    private void jTextFieldTermoPesquisadoFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextFieldTermoPesquisadoFocusLost
        if (jTextFieldTermoPesquisado.getText().isEmpty()) {
        jTextFieldTermoPesquisado.setText("Insira o termo de pesquisa..."); // Volta o texto se ficar vazio
        jTextFieldTermoPesquisado.setForeground(java.awt.Color.GRAY);
        }
    }//GEN-LAST:event_jTextFieldTermoPesquisadoFocusLost

    private void jButtonExcluirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonExcluirActionPerformed
        int linhaSelecionada = jTableResultados.getSelectedRow();
        
        if (linhaSelecionada == -1) {
            javax.swing.JOptionPane.showMessageDialog(this, "Selecione um registro na tabela para excluir.");
            return;
        }

        int confirmacao = javax.swing.JOptionPane.showConfirmDialog(this, "Tem certeza que deseja excluir este registro?", "Confirmar Exclusão", javax.swing.JOptionPane.YES_NO_OPTION);
        if (confirmacao != javax.swing.JOptionPane.YES_OPTION) { //confirmação de exclusão do registro
            return;
        }

       long id = Long.parseLong(jTableResultados.getValueAt(linhaSelecionada, 0).toString());

        if ("CIDADE".equals(this.tipoOrigemTela)) {
            Cidade cid = new Cidade();
            cid.setId(id); // O Hibernate precisa saber qual o ID para apagar
            
            CidadeDAO dao = new CidadeDAO();
            if (dao.Excluir(cid)) {
                errorMsg.setText("Excluído com sucesso!");
                errorMsg.setForeground(java.awt.Color.BLACK);
                jButtonPesquisar.doClick(); // Clica no botão Pesquisar p recarregar a tabela
            } else {
                errorMsg.setText("Erro ao excluir a cidade.");
                errorMsg.setForeground(java.awt.Color.RED);
            }
            
        } else if ("CLIENTE".equals(this.tipoOrigemTela)) {
            Cliente cli = new Cliente();
            cli.setId(id);
            
            ClienteDAO dao = new ClienteDAO();
            if (dao.Excluir(cli)) {
                errorMsg.setText("Excluído com sucesso!");
                errorMsg.setForeground(java.awt.Color.BLACK);
                jButtonPesquisar.doClick(); // Clica no botão Pesquisar p recarregar a tabela
            } else {
                errorMsg.setText("Erro ao excluir a cidade.");
                errorMsg.setForeground(java.awt.Color.RED);
            }
        }      
    }//GEN-LAST:event_jButtonExcluirActionPerformed

    private void jButtonAlterarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonAlterarActionPerformed
        int linhaSelecionada = jTableResultados.getSelectedRow();
        if (linhaSelecionada == -1) {
            javax.swing.JOptionPane.showMessageDialog(this, "Selecione um registro na tabela para alterar.");
            return;
        }

        if ("CIDADE".equals(this.tipoOrigemTela)) {
            // Pega os dados da linha clicada
            long id = Long.parseLong(jTableResultados.getValueAt(linhaSelecionada, 0).toString());
            String nome = (String) jTableResultados.getValueAt(linhaSelecionada, 1);
            String uf = (String) jTableResultados.getValueAt(linhaSelecionada, 2);

            // Cria uma cidade com os dados
            Cidade cidadeEdit = new Cidade();
            cidadeEdit.setId(id);
            cidadeEdit.setNome(nome);
            cidadeEdit.setUF(uf);

            // Abre a TelaCidade enviando a cidade selecionada
            TelaCidade tela = new TelaCidade(cidadeEdit);
            tela.setLocationRelativeTo(null);
            tela.setVisible(true);
            
            this.dispose(); //fecha a tela de lista
            
        } else if ("CLIENTE".equals(this.tipoOrigemTela)) {
            // Tem que implementar qnd add a tela de cliente
        }
    }//GEN-LAST:event_jButtonAlterarActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(() -> new Listar().setVisible(true));
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel errorMsg;
    private javax.swing.JButton jButtonAlterar;
    private javax.swing.JButton jButtonExcluir;
    private javax.swing.JButton jButtonPesquisar;
    private javax.swing.JLabel jLabelTituloPesquisa;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable jTableResultados;
    private javax.swing.JTextField jTextFieldTermoPesquisado;
    // End of variables declaration//GEN-END:variables
}