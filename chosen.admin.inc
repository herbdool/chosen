<?php

/**
 * @file
 * Chosen administration pages.
 */

/**
 * General configuration form.
 */
function chosen_admin_settings() {
  $form['chosen_usage_settings_custom_selectors'] = array(
    '#type' => 'textfield',
    '#title' => t('Enable Chosen on the following elements'),
    '#description' => t('jQuery selectors to use chosen on eg: <code>.chosen-select</code> or <code>#chosen-select</code> or <code>select</code> to use on all select element.'),
    '#default_value' => variable_get('chosen_usage_settings_custom_selectors', 'select'),
  );
  
  return system_settings_form($form);
}
