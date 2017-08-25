<?php

/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_binary_object_admin(array $form, array &$form_state) {
  module_load_include('inc', 'islandora', 'includes/utilities');
  module_load_include('inc', 'islandora', 'includes/solution_packs');

  $form += islandora_viewers_form('islandora_binary_csv_viewers', 'text/csv');
  $form['csv_viewers'] = $form['viewers'];
  $form['csv_viewers']['#title'] = t('CSV Viewers');
  unset($form['viewers']);
  $form += islandora_viewers_form('islandora_binary_zip_viewers', 'application/zip');
  $form['zip_viewers'] = $form['viewers'];
  $form['zip_viewers']['#title'] = t('ZIP Viewers');
  unset($form['viewers']);

  return system_settings_form($form);
}

