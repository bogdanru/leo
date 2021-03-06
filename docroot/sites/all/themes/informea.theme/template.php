<?php
/**
 * @file
 * template.php
 */

/**
 * Preprocesses variables for page template.
 *
 * @param $variables
 *   An associative array with generated variables.
 *
 * @return
 *   Nothing.
 */
function informea_theme_preprocess_page(&$variables) {
  $search_form = drupal_get_form('search_form');

  $variables['search_box'] = drupal_render($search_form);

  if ($variables['is_front']) {
    // Loads the enabled countries.
    $variables['countries'] = countries_get_countries('name', array('enabled' => COUNTRIES_ENABLED));

    // Adds the front page JavaScript file to the page.
    drupal_add_js(drupal_get_path('theme', 'informea_theme') . '/js/front.js');
  }
}

/**
 * Performs alterations before a form is rendered.
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 * @param $form_id
 *   String representing the name of the form itself.
 *
 * @return
 *   Nothing.
 */
function informea_theme_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_form') {
    $form['#attributes']['class'][] = 'navbar-form';
    $form['#attributes']['class'][] = 'navbar-right';
  }
}
