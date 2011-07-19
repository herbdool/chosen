<?php
// $Id$

/**
 * @file
 * Administration for Access Links
 */

function chosen_admin_settings() {
  $form = array();
  
  $form['access_links_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display Settings'),
  );
  
  $form['access_links_display']['access_links_show_in_node_body'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Access links in content'),
    '#description' => t('The links will be appended to the content body.'),
    '#default_value' => variable_get('access_links_show_in_node_body', 0),
  );
  
  $form['access_links_display']['access_links_show_in_block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Access links in a block'),
    '#description' => t('The links will be shown in a block. You need to enable the block !here.', array('!here' => l(t('here'), 'admin/structure/block'))),
    '#default_value' => variable_get('access_links_show_in_block', 0),
  );
  
  return system_settings_form($form);
}