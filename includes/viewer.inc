<?php

/**
 * @file
 * Holds the viewer callbacks.
 */

/**
 * Selects and calls viewers
 *
 * @param AbstractObject $object
 *   The object the viewer will display
 * @param string $mimetype
 *   The Drupal form state
 *
 * @return string
 *   The callback to the viewer module. Returns a rendered viewer.
 */
function islandora_binary_object_get_viewer(AbstractObject $object, $mimetype) {
  module_load_include('inc', 'islandora', 'islandora');
  module_load_include('inc', 'islandora', 'includes/solution_packs');

  if ($mimetype == 'text/csv') {
    $params = array();
    $params['url'] = url("islandora/object/{$object->id}/datastream/OBJ/view", array('absolute' => TRUE));

    return islandora_get_viewer($params, 'islandora_binary_csv_viewers', $object);
  }
  if ($mimetype == 'application/zip') {
    $params = array();
    $params['dsid'] = 'OBJ';

    return islandora_get_viewer($params, 'islandora_binary_zip_viewers', $object);
  }
  return null;
}

