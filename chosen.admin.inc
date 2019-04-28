<?php
/**
 * @file
 * Chosen administration pages.
 */

/**
 * Returns with the general configuration form.
 */
function chosen_admin_settings($form, &$form_state) {
  $config = config('chosen.settings');

  $form['#config'] = 'chosen.settings';

  $form['minimum_single'] = array(
    '#type' => 'select',
    '#title' => t('Minimum number of options for single select'),
    '#options' => array_merge(array('0' => t('Always apply')), backdrop_map_assoc(range(1, 25))),
    '#default_value' => $config->get('minimum_single'),
    '#description' => t('The minimum number of options to apply Chosen for single select fields. Example : choosing 10 will only apply Chosen if the number of options is greater or equal to 10.'),
  );

  $form['minimum_multiple'] = array(
    '#type' => 'select',
    '#title' => t('Minimum number of options for multi select'),
    '#options' => array_merge(array('0' => t('Always apply')), backdrop_map_assoc(range(1, 25))),
    '#default_value' => $config->get('minimum_multiple'),
    '#description' => t('The minimum number of options to apply Chosen for multi select fields. Example : choosing 10 will only apply Chosen if the number of options is greater or equal to 10.'),
  );

  $form['disable_search_threshold'] = array(
    '#type' => 'select',
    '#title' => t('Minimum number to show Search on Single Select'),
    '#options' => array_merge(array('0' => t('Never apply')), backdrop_map_assoc(range(1, 25))),
    '#default_value' => $config->get('disable_search_threshold'),
    '#description' => t('The minimum number of options to apply Chosen search box. Example : choosing 10 will only apply Chosen search if the number of options is greater or equal to 10.'),
  );

  $form['minimum_width'] = array(
    '#type' => 'number',
    '#title' => t('Minimum width of widget'),
    '#field_suffix' => 'px',
    '#default_value' => $config->get('minimum_width'),
    '#description' => t('The minimum width of the Chosen widget. Leave blank to have chosen determine this.'),
  );

  $form['jquery_selector'] = array(
    '#type' => 'textarea',
    '#title' => t('Apply Chosen to the following elements'),
    '#description' => t('A comma-separated list of jQuery selectors to apply Chosen to, such as <code>select#edit-operation, select#edit-type</code> or <code>.chosen-select</code>. Defaults to <code>select</code> to apply Chosen to all <code>&lt;select&gt;</code> elements.'),
    '#default_value' => $config->get('jquery_selector'),
  );

  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Chosen general options'),
  );
  $form['options']['search_contains'] = array(
    '#type' => 'checkbox',
    '#title' => t('Search also in the middle of words'),
    '#default_value' => $config->get('search_contains'),
    '#description' => t('Per default chosen searches only at beginning of words. Enable this option will also find results in the middle of words.
      Example: Search for <em>land</em> will also find <code>Switzer<strong>land</strong></code>.'),
  );
  $form['options']['disable_search'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable search box'),
    '#default_value' => $config->get('disable_search'),
    '#description' => t('Enable or disable the search box in the results list to filter out possible options.'),
  );

  $form['theme_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Chosen per theme options'),
  );

  $form['theme_options']['disabled_themes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Disable the default Chosen theme for the following themes'),
    '#options' => _chosen_enabled_themes_options(),
    '#default_value' => $config->get('disabled_themes'),
    '#description' => t('Enable or disable the default Chosen CSS file. Select a theme if it contains custom styles for Chosen replacements.'),
  );

  $form['options']['include'] = array(
    '#type' => 'radios',
    '#title' => t('Use chosen for admin pages and/or front end pages'),
    '#options' => array(
      CHOSEN_INCLUDE_EVERYWHERE => t('Include Chosen on every page'),
      CHOSEN_INCLUDE_ADMIN => t('Include Chosen only on admin pages'),
      CHOSEN_INCLUDE_NO_ADMIN => t('Include Chosen only on front end pages'),
    ),
    '#default_value' => $config->get('include'),
  );

  $form['options']['allow_single_deselect'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow deselect on single selects'),
    '#default_value' => $config->get('allow_single_deselect'),
    '#description' => t("Enable or disable option deselection for single select fields. This will only work if the first option has blank text."),
  );

  $form['strings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Chosen strings'),
  );
  $form['strings']['placeholder_text_multiple'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text of multiple selects'),
    '#required' => TRUE,
    '#default_value' => $config->get('placeholder_text_multiple'),
  );
  $form['strings']['placeholder_text_single'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text of single selects'),
    '#required' => TRUE,
    '#default_value' => $config->get('placeholder_text_single'),
  );
  $form['strings']['no_results_text'] = array(
    '#type' => 'textfield',
    '#title' => t('No results text'),
    '#required' => TRUE,
    '#default_value' => $config->get('no_results_text'),
  );

  return system_settings_form($form);
}

/**
 * Helper function to get options for enabled themes.
 */
function _chosen_enabled_themes_options() {
  $options = array();

  // Get the list of themes.
  $themes = list_themes();

  foreach ($themes as $theme) {
    // Only create options for enabled themes.
    if ($theme->status) {
      $options[$theme->name] = $theme->info['name'];
    }
  }

  return $options;
}
