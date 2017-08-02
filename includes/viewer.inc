<?php

function islandora_binary_object_get_viewer($object, $mimetype) {
  module_load_include('inc', 'islandora', 'islandora');
  module_load_include('inc', 'islandora', 'includes/solution_packs');
  if ($mimetype == 'text/csv') {
    $params = array();
    return islandora_get_viewer($params, 'islandora_binary_csv_viewers', $object);
  }
  if ($mimetype == 'application/zip') {
    $params = array();
    return islandora_get_viewer($params, 'islandora_binary_zip_viewers', $object);
  }
  return null;
}
