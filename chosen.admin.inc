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
    '#title' => t('Enable Chosen in Administration interface'),
    '#description' => t('Check if you want to enable Chosen in the admin ui.'),
    '#default_value' => variable_get('chosen_usage_settings_use_in_admin', 0),
  );
  
  $form['chosen_usage_settings']['chosen_usage_settings_custom_selectors'] = array(
    '#type' => 'textfield',
    '#title' => t('Enable Chosen on the following elements'),
    '#description' => t('jQuery selectos to use chosen on. eg. .chosen-select or #chosen-select or select to use on all select element.'),
    '#default_value' => variable_get('chosen_usage_settings_custom_selectors', ''),
  );
  
  return system_settings_form($form);
}