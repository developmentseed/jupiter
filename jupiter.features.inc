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
