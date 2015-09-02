<?php
/**
 * @file
 * The view for displaying the SharedShelf media downloaded to Drupal so that
 * paging is available within the Add from SharedShelf media feature.
 */

/**
 * Implements hook_views_default_view().
 */
function media_sharedshelf_views_default_views() {
  $view = new view();
  $view->name = 'media_sharedshelf_my_images';
  $view->description = t('Display the existing SharedShelf media downloaded to Drupal');
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = t('My SharedShelf Images');
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = t('My SharedShelf Images');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'file';
  $handler->display->display_options['row_options']['view_mode'] = 'preview';
  $handler->display->display_options['row_options']['links'] = 1;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = TRUE;
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: File: Path */
  $handler->display->display_options['filters']['uri']['id'] = 'uri';
  $handler->display->display_options['filters']['uri']['table'] = 'file_managed';
  $handler->display->display_options['filters']['uri']['field'] = 'uri';
  $handler->display->display_options['filters']['uri']['operator'] = 'contains';
  $handler->display->display_options['filters']['uri']['value'] = 'sharedshelf';
	/* Filter criterion: File: Path */
	$handler->display->display_options['filters']['uri_1']['id'] = 'uri_1';
	$handler->display->display_options['filters']['uri_1']['table'] = 'file_managed';
	$handler->display->display_options['filters']['uri_1']['field'] = 'uri';
	$handler->display->display_options['filters']['uri_1']['operator'] = 'not';
	$handler->display->display_options['filters']['uri_1']['value'] = 'pdfthumbs';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  // Export ends here.
  // Add view to list of views provided.
  $views[$view->name] = $view;
  return $views;
}
