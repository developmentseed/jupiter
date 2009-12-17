<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jupiter_ctools_plugin_api() {
  module_load_include('inc', 'jupiter', 'jupiter.defaults');
  $args = func_get_args();
  return call_user_func_array('_jupiter_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function jupiter_node_info() {
  module_load_include('inc', 'jupiter', 'jupiter.features.node');
  $args = func_get_args();
  return call_user_func_array('_jupiter_node_info', $args);
}

/**
 * Implementation of hook_spaces_presets().
 */
function jupiter_spaces_presets() {
  module_load_include('inc', 'jupiter', 'jupiter.defaults');
  $args = func_get_args();
  return call_user_func_array('_jupiter_spaces_presets', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function jupiter_user_default_permissions() {
  module_load_include('inc', 'jupiter', 'jupiter.defaults');
  $args = func_get_args();
  return call_user_func_array('_jupiter_user_default_permissions', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function jupiter_strongarm() {
  module_load_include('inc', 'jupiter', 'jupiter.defaults');
  $args = func_get_args();
  return call_user_func_array('_jupiter_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function jupiter_views_default_views() {
  module_load_include('inc', 'jupiter', 'jupiter.features.views');
  $args = func_get_args();
  return call_user_func_array('_jupiter_views_default_views', $args);
}
