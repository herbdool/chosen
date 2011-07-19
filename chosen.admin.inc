<?php
// $Id$

/**
 * @file
 * Administration for Access Links
 */

function chosen_admin_settings() {
  $form = array();
  
  $form['chosen_usage_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Usage'),
  );
  
  $form['chosen_usage_settings']['chosen_usage_settings_use_in_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Chosen in administration user interface'),
    '#description' => t('Check if you want to enable Chosen in the administration user interface.'),
    '#default_value' => variable_get('chosen_usage_settings_use_in_admin', 0),
  );
  
  $form['chosen_usage_settings']['chosen_usage_settings_custom_selectors'] = array(
    '#type' => 'textfield',
    '#title' => t('Enable Chosen on the following elements'),
    '#description' => t('jQuery selectors to use chosen on eg: <code>.chosen-select</code> or <code>#chosen-select</code> or <code>select</code> to use on all select element.'),
    '#default_value' => variable_get('chosen_usage_settings_custom_selectors', 'select'),
  );
  
  return system_settings_form($form);
}
