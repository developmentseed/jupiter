<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _jupiter_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "system" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _jupiter_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_group';
  $strongarm->value = 'group';

  $export['og_content_type_usage_group'] = $strongarm;
  return $export;
}
