<?php

/**
 * @file
 * Chosen administration pages.
 */

/**
 * General configuration form.
 */
function chosen_admin_settings() {
  $form['chosen_jquery_selector'] = array(
    '#type' => 'textarea',
    '#title' => t('Apply Chosen to the following elements'),
    '#description' => t('A jQuery selector to find elements to apply Chosen to, such as <code>.chosen-select</code>. Defaults to <code>select</code> to apply Chosen to all <code>&lt;select&gt;</code> elements.'),
    '#default_value' => variable_get('chosen_jquery_selector', 'select'),
  );
  
  return system_settings_form($form);
}
